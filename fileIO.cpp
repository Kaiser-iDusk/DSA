#include<iostream>
#include<string>
#include<fstream>
#include<queue>

using namespace std;

void start_game() {
	//using namespace std;

	ofstream games_write("games.txt", ofstream::out | ofstream::app);	
	if(games_write.is_open())
		games_write.close();
}

int score_extract(string& line){
    //using namespace std;
    
    string sbstr = line.substr(0, 3);
    //cout << sbstr << endl;
    int ans = 0;
    for(int i = 0; i< 3; i++){
        ans += (sbstr[i] - '0');
        ans *= 10;
    }
    return ans / 10;
}

string char_extract(string& line){
    //using namespace std;
    return line.substr(4);
}

void read_scores(priority_queue<pair<int, string>>& pq) {
	//using namespace std;

	ifstream games_read("games.txt");
	string line;
	if (games_read.is_open()) {
		while (getline(games_read, line)) {
			//cout << line << endl;
            int int_part = score_extract(line);
            string char_part = char_extract(line);
            //cout << char_part << endl;
            pq.push(make_pair(int_part, char_part));
		}
		games_read.close();
	}
	else {
		cout << "Error: Unable to write to file games.txt" << endl;
	}
}

string make_string_to_int(int val){
    //using namespace std;

    string ans = "000";
    int i = 2;
    while(val){
        ans[i--] += (val % 10);
        val /= 10; 
    }
    return ans;
}
void make_highscores(priority_queue<pair<int, string>>& pq, int count){
    //using namespace std;

	ofstream writer("highscores.txt", ofstream::out);	
	if(writer.is_open()){
        while(!pq.empty() && (count--)){
            pair<int, string> p = pq.top();
            pq.pop();
            string str_score = make_string_to_int(p.first);
            writer << (str_score + "|" + p.second) << endl;
        }
        writer.close();
    }
    else{
        cout << "Error: Unable to lock/open highscores.txt" << endl;
    }
}
void deleteDB(){
    //using namespace std;

    std::ofstream ofs;
    ofs.open("games.txt", ofstream::out | ofstream::trunc);
    ofs.close();
}

string char_to_string(char* inputBox){
    string ans = "";
    int i = 0;
    while(inputBox[i] != '\0'){
        ans += inputBox[i];
        i++;
    }
    return ans;
}

int main(){
    char input = "Hello Boy";
    cout << input << endl;
    cout << char_to_string(input) << endl; 
    return 0;
}