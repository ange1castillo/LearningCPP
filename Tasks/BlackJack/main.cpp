#include <algorithm>
#include <cassert>
#include <iostream>

#include "Random.h"

namespace Settings{
	constexpr int winningScore { 21 };
	constexpr int minimumDealerScore { 17 };
}

enum GameResults{
	playerWon,
	dealerWon,
	tie,
};

struct Card {
	enum Rank{
		ace,
		_2,
		_3,
		_4,
		_5,
		_6,
		_7,
		_8,
		_9,
		_10,
		jack,
		queen,
		king,
		maxRanks,
	};

	enum Suit{
		clubs,
		diamonds,
		hearts,
		spades,
		maxSuits,
	};

	Rank rank {};
	Suit suit {};

	constexpr static std::array<Rank, maxRanks> allRanks { ace, _2, _3, _4, _5, _6, _7, _8, _9, _10, jack, queen, king };
	constexpr static std::array<Suit, maxSuits> allSuits { clubs, diamonds, hearts, spades };

	friend std::ostream& operator<<(std::ostream& out, const Card& card){
		
		constexpr static std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
		constexpr static std::array suits { 'C', 'D', 'H', 'S' };

		out << ranks[card.rank] << suits[card.suit];
		return out;
	}

	int getCardValue() const {
		constexpr static std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
		return rankValues[rank];
	}
};

class Deck{
	private:
		std::array<Card, 52> m_deck {};
		std::size_t m_nextCardIndex {0};

	public:
		Deck(){
			std::size_t index {0};
			for(const auto& suit : Card::allSuits){
				for(const auto& rank : Card::allRanks){
					m_deck[index++] = Card { rank, suit };
				}
			}
		}

		void shuffle() {
			std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
			m_nextCardIndex = 0;
		}

		Card dealCard() {
			assert(m_nextCardIndex != 52);
			return m_deck[m_nextCardIndex++];
		}
};

struct Player {
	int score {};
	int aces {};

	void addScore(Card card){
		score += card.getCardValue();
		if(card.rank == Card::ace){
			aces++;
		}
	}

	void removeAces(){
		while(score > Settings::winningScore || aces > 0){
			score -= 10;
			--aces;
		}
		std::cout << "and will now be turned into a 1. Your new score is: " << score << '\n';
	}
};

char getPlayerInput(){
	std::cout << "(h) to hit, or (s) to stand: ";
	while(true){
		char input {};
		std::cin >> input;

		if(!std::cin){
			std::cout << "Please enter either (h) to hit or (s) to stand.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return input;
	}
}

bool dealerTurn(Deck& deck, Player& dealer){
	while(dealer.score < Settings::minimumDealerScore){
		Card cardDealt { deck.dealCard() };
		dealer.addScore(cardDealt);
		std::cout << "The dealer flips a " << cardDealt << ". They now have: " << dealer.score << '\n';

		if(dealer.score == Settings::winningScore){
			return false;
		}

		if(dealer.score > Settings::winningScore && dealer.aces > 0){
			std::cout << "The dealer has an ace ";
			dealer.removeAces();
		}

		if(dealer.score > Settings::winningScore) {
			std::cout << "The dealer went bust!\n";
			return true;
		}

	}

	return false;
}

bool playerTurn(Deck& deck, Player& player){ 
	while(getPlayerInput() != 's'){
		Card cardDealt { deck.dealCard() };
		player.addScore(cardDealt);
		std::cout << "You were dealt " << cardDealt << ". You now have: " << player.score << '\n';

		if(player.score == Settings::winningScore){
			return false;
		}

		if(player.score > Settings::winningScore && player.aces > 0){
			std::cout << "You have an ace ";
			player.removeAces();
		}

		if(player.score > Settings::winningScore) {
			std::cout << "You went bust!\n";
			return true;
		}
	}

	return false;
}

GameResults startRound(){
	Deck deck {};
	deck.shuffle();

	Player dealer {};
	Card dealerCard { deck.dealCard() };
	dealer.addScore(dealerCard);
	std::cout << "The dealer is showing: " << dealer.score << '\n';

	Player player { };
	Card playerCard1 { deck.dealCard() };
	Card playerCard2 { deck.dealCard() };
	player.addScore(playerCard1);
	player.addScore(playerCard2);
	std::cout << "You have score: " << player.score << '\n';

	if(player.score != Settings::winningScore){
		if(playerTurn(deck, player)){
			return GameResults::dealerWon;
		};
	}

	if(dealerTurn(deck, dealer)){
		return GameResults::playerWon;
	}

	if(player.score == dealer.score){
		return GameResults::tie;
	}

	return (player.score > dealer.score) ? GameResults::playerWon : GameResults::dealerWon;
}

void play(){
	switch(startRound()){
		case GameResults::dealerWon:
			std::cout << "You lose!\n";
			break;
		case GameResults::playerWon:
			std::cout << "You win!\n";
			break;
		case GameResults::tie:
			std::cout << "It's a tie!\n";
			break;
	}
}

void startGame(){
	play();
}

int main(){
	startGame();

	return 0;
}
