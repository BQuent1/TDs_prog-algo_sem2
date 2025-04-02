#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <random>
#include <algorithm>
#include <iterator>



enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};


const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

const std::vector<int> expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};


const std::vector<float> expected_insect_counts_probabilities {
    75, // ClassicBee
    500.f, // Ladybug
    100.f, // Butterfly
    200.f, // Dragonfly
    4000.f, // Ant
    1500.f, // Grasshopper
    600.f, // Beetle
    100.f, // Wasp
    400.f, // Caterpillar
    900.f, // Spider 
    50.f, // GuimielBee
};


std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        auto& previous_observation { observations.back() };
        if(previous_observation.first == random_insect) {
            previous_observation.second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts){
    std::vector<float> probabilities(counts.size());
    int total_count = 0;
    for (int count : counts) {
        total_count += count;
    }
    for (size_t i = 0; i < counts.size(); ++i) {
        probabilities[i] = static_cast<float>(counts[i]) / total_count;
    }
    return probabilities;
}


int main(){
    std::vector<std::pair<Insect, int>> observations = get_insect_observations(10000, probabilities_from_count(expected_insect_counts));
    std::unordered_map<Insect, int> insect_count_map;
    for (const auto& observation : observations) {
        if (insect_count_map.find(observation.first) == insect_count_map.end()) {
            insect_count_map.insert({observation.first, observation.second});
        }
        else {
            insect_count_map[observation.first] += observation.second;
        }
    }

    std::cout << "Insect counts:" << std::endl;
    for (const auto& insect_count : insect_count_map) {
        std::cout << insect_to_string.at(insect_count.first) << ": " << insect_count.second << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Probabilities:" << std::endl;
    std::vector<int> counts;
    for (const auto& insect_count : insect_count_map) {
        counts.push_back(insect_count.second);
    }
    std::vector<float> probabilities = probabilities_from_count(counts);
    for (size_t i = 0; i < probabilities.size(); ++i) {
        std::cout << insect_to_string.at(insect_values[i]) << ": " << probabilities[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Probabilities of observed insects vs expected probabilities:" << std::endl;
    for (size_t i = 0; i < probabilities.size(); ++i) {
        if(expected_insect_counts_probabilities[i] - probabilities[i] <= 0.01f) {
            std::cout << insect_to_string.at(insect_values[i]) << ": " << probabilities[i] << " vs " << probabilities_from_count(expected_insect_counts)[i] << " OK" << std::endl;
        }
        else{
            std::cout << insect_to_string.at(insect_values[i]) << ": " << probabilities[i] << " vs " << probabilities_from_count(expected_insect_counts)[i] << " BAD" << std::endl;
        }
    }

    return 0;
}