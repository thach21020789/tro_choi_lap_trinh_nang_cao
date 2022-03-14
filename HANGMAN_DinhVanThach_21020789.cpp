#include<bits/stdc++.h>
using namespace std;
const string WORD_LIST[] = {
"angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
string ChoseWord()
{
	srand(time(NULL));
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}
void update(string &secretWord , string &guessWord, char guess);
void renderGame(string guessWord, int badGuessCount);
string readGuess();
bool contain(char guess, string secretWord);
char readCharguess();

//int, long long,double, float, string, char, 2.3456785678, 2.000
// 1. for(; ;), while(), do {
//                             ....}while(dieu kien lap);
const int Max_bad_guess = 7; 
int main(){
    string secretWord = ChoseWord();
    string guessWord  = string(secretWord.length(),'-');
    int badGuessCount = 0;
    do{
    	renderGame(guessWord, badGuessCount);
		char guess = readCharguess();
		if(contain(guess, secretWord)){
			update(secretWord, guessWord, guess);
		}else badGuessCount++;
		system("cls");
	}while(badGuessCount < Max_bad_guess && secretWord != guessWord);
	if( badGuessCount == 7) renderGame(guessWord, badGuessCount);
	
	if(badGuessCount < Max_bad_guess){
		cout << "Congratulations! you win! " << endl;
	}else cout << "you lost. " << secretWord << endl;
	return 0;
}

const string FIGURE[] = {
" ------------- \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " |  | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /| \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /|\\ \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /|\\ \n"
 " | / \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /|\\ \n"
 " | / \\ \n"
 " | \n"
 " ----- \n",
 
};
void update(string &secretWord , string &guessWord, char guess)
{
   for (int i = 0; i < secretWord.length(); i++){
   	if(secretWord[i] == guess){
   		guessWord[i] = guess;
	   }
   }
  cout << guessWord << endl;
}

void renderGame(string guessWord, int badGuessCount){
	cout << FIGURE[badGuessCount] << endl;
	cout << guessWord << endl;
	cout << "Number of Wrong : " << badGuessCount << endl;
}

bool contain(char guess, string secretWord){
	for(int i = 0 ; i < secretWord.length() ; i++){
		if(secretWord[i] == guess) {
			return true;
		}
	}
	return false;
}
char readCharguess(){
	cout << "Enter your char : "; 
	char ch; cin >> ch;
	return ch;
}
