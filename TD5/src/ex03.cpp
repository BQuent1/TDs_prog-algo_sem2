#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>


enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    const int hash() const {
        return static_cast<int>(kind) * 13 + static_cast<int>(value);
    }

};

bool operator==(const Card& lhs, const Card& rhs) {
    return lhs.kind == rhs.kind && lhs.value == rhs.value;
}


std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}



int main(){
    std::vector<Card> cards = {
        {CardKind::Heart, CardValue::Two}, {CardKind::Heart, CardValue::Three}, {CardKind::Heart, CardValue::Four},
        {CardKind::Heart, CardValue::Five}, {CardKind::Heart, CardValue::Six}, {CardKind::Heart, CardValue::Seven},
        {CardKind::Heart, CardValue::Eight}, {CardKind::Heart, CardValue::Nine}, {CardKind::Heart, CardValue::Ten},
        {CardKind::Heart, CardValue::Jack}, {CardKind::Heart, CardValue::Queen}, {CardKind::Heart, CardValue::King},
        {CardKind::Heart, CardValue::Ace},

        {CardKind::Diamond, CardValue::Two}, {CardKind::Diamond, CardValue::Three}, {CardKind::Diamond, CardValue::Four},
        {CardKind::Diamond, CardValue::Five}, {CardKind::Diamond, CardValue::Six}, {CardKind::Diamond, CardValue::Seven},
        {CardKind::Diamond, CardValue::Eight}, {CardKind::Diamond, CardValue::Nine}, {CardKind::Diamond, CardValue::Ten},
        {CardKind::Diamond, CardValue::Jack}, {CardKind::Diamond, CardValue::Queen}, {CardKind::Diamond, CardValue::King},
        {CardKind::Diamond, CardValue::Ace},

        {CardKind::Club, CardValue::Two}, {CardKind::Club, CardValue::Three}, {CardKind::Club, CardValue::Four},
        {CardKind::Club, CardValue::Five}, {CardKind::Club, CardValue::Six}, {CardKind::Club, CardValue::Seven},
        {CardKind::Club, CardValue::Eight}, {CardKind::Club, CardValue::Nine}, {CardKind::Club, CardValue::Ten},
        {CardKind::Club, CardValue::Jack}, {CardKind::Club, CardValue::Queen}, {CardKind::Club, CardValue::King},
        {CardKind::Club, CardValue::Ace},

        {CardKind::Spade, CardValue::Two}, {CardKind::Spade, CardValue::Three}, {CardKind::Spade, CardValue::Four},
        {CardKind::Spade, CardValue::Five}, {CardKind::Spade, CardValue::Six}, {CardKind::Spade, CardValue::Seven},
        {CardKind::Spade, CardValue::Eight}, {CardKind::Spade, CardValue::Nine}, {CardKind::Spade, CardValue::Ten},
        {CardKind::Spade, CardValue::Jack}, {CardKind::Spade, CardValue::Queen}, {CardKind::Spade, CardValue::King},
        {CardKind::Spade, CardValue::Ace}
    };

    for (const auto& card : cards) {
        std::cout << "Card: Kind = " << static_cast<int>(card.kind)
                  << ", Value = " << static_cast<int>(card.value)
                  << ", Hash = " << card.hash() << std::endl;
    }
}