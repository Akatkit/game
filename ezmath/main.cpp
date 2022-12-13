#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

const int limit = 50;
string name_player;
int score = 0;

template <class Rep, class Period>
  void sleep_for (const chrono::duration<Rep,Period>& rel_time);

int random(int min, int max) {
	static std::random_device device{};
	static std::default_random_engine engine{ device() };
	std::uniform_int_distribution<int> distribution{ min, max };
	return distribution(engine);
}

void player_information() {
    cout << "Hi, what's your name? (just write a word)"<< endl;
    cin >> name_player;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << name_player << ", right?" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
}

void start_game() {
    cout << "ok..." << endl << "Welcom to ezmath" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "You will need to answer 50 questions, GO!!!" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    for (int i = 1; i <= limit; i++) {
        int number_one = random(1, 100);
        int number_two = number_one + random(1, 100);
        int true_ans = number_one+number_two;
        int ans_player = 0;
        cout << "Score: " << score << endl;
        cout << "Question" << i << ": " << number_one << "+" << number_two << " = ";
        cin >> ans_player;
        if (ans_player == true_ans) {
            cout << "Good job " << name_player << endl;
            score++;
        }
        else {
            cout << "You wrong " << name_player << endl;
        }
    }
    if (score <= 20) {
        cout << "Wow " << score << " I think you will need to study grade 1 again " << name_player << " lol" << endl;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(4000));
        cout << "thank you for playing this game :)";
    }
    else {
        cout << "Congratulation! You got " << score << endl;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "thank you for playing this game :)";
    }
}

int main()
{
    player_information();
    start_game();
    return 0;
}
