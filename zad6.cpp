#include <iostream>
#include <array>
#include <cstdlib> // ��� ������� rand() � srand()

int getRandomNumber(int min,int max)
{
 	static const double fraction=1.0/(static_cast<double>(RAND_MAX) + 1.0);
 	return static_cast<int>(rand() * fraction * (max-min+1) + min);
}


enum Mast {
	TREF,
	BUBNA,
	CHERVI,
	PIKI,
	MAST_LENGTH
};

enum Dostoinstvo {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	VALET,
	DAMA,
	KOROL,
	TUZ,
	DOSTOINSTVO_LENGTH
};

struct Card {
	Mast mast;
	Dostoinstvo dostoinstvo;
};



void PrintCard(const Card &card){
	switch (card.dostoinstvo){
		case 	TWO:
			std::cout <<  "2 ";
			break;
		case 	THREE:
			std::cout <<  "3 ";
			break;
		case 	FOUR:
			std::cout <<  "4 ";
			break;
		case 	FIVE:
			std::cout <<  "5 ";
			break;
		case 	SIX:
			std::cout <<  "6 ";
			break;
		case 	SEVEN:
			std::cout <<  "7 ";
			break;
		case 	EIGHT:
			std::cout <<  "8 ";
			break;
		case 	NINE:
			std::cout <<  "9 ";
			break;
		case 	TEN:
			std::cout <<  "10 ";
			break;
		case 	VALET:
			std::cout <<  "valet ";
			break;
		case 	DAMA:
			std::cout <<  "dama ";
			break;
		case 	KOROL:
			std::cout <<  "korol ";
			break;
		case 	TUZ:
			std::cout <<  "tuz ";
			break;
		default:
			std::cout <<  "ERROR IN dostoinstvo!!! ";
		}
	switch (card.mast){
		case TREF:
			std::cout <<  "TREF (kresta)";
			break;
		case 	BUBNA:
			std::cout <<  "BUBNA (rombik)";
			break;
		case 	CHERVI:
			std::cout <<  "CHERVI (serdechko)";
			break;
		case 	PIKI:
			std::cout <<  "PIKI ";
			break;
		default:
			std::cout <<  "ERROR in mast!!! ";
		}
	//std::cout <<  '\n';
}

void swapCard(Card &a, Card &b){
	Card temp=a;
	a=b;
	b=temp;
}


void printDeck(const std::array<Card,52> &deck){
	for(Card a: deck){
		PrintCard(a);
		//std::cout<<'\n';
		}
}


void shuffleDeck(std::array<Card,52> &deck){
	srand(static_cast<unsigned int>(time(0)));
	std::cout<<"\n=== Shuffling the deck ===\n";
	int ra;
	for(Card &a: deck){
		ra=getRandomNumber(0,51);
		swapCard(a,deck[ra]);
	}
}

int getCardValue(Card &card){
	int rez{static_cast<int>(card.dostoinstvo)};
	if(rez<9) return rez+2;
	else if(rez<12) return 10;
	else return 11;
}


int main(){    
	std::array<Card,52> deck;
	int ind;
	for(int i=0; i<DOSTOINSTVO_LENGTH; ++i){
		for(int j=0; j<MAST_LENGTH;++j){
			ind= j*(DOSTOINSTVO_LENGTH)+i;
			deck[ind].mast=static_cast<Mast>(j);
			deck[ind].dostoinstvo=static_cast<Dostoinstvo>(i);
		}
	}
	
	printDeck(deck);

	shuffleDeck(deck);

	printDeck(deck);
	std::cout<<'\n';
	PrintCard(deck[51]);
	std::cout<<'\t'<<getCardValue(deck[51])<<'\n';
	PrintCard(deck[50]);
	std::cout<<'\t'<<getCardValue(deck[50])<<'\n';
	PrintCard(deck[49]);
	std::cout<<'\t'<<getCardValue(deck[49])<<'\n';
	return 0;
}