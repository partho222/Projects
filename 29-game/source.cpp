/* Tariq ahmed khan - Daffodil */

#include <bits/stdc++.h>

/*####### Template Starts Here #######*/

#define pi 2*acos(0.0)
#define scan(x) scanf("%d",&x)
#define sf scanf
#define pf printf
#define pb push_back
#define memoclr(n,x) memset(n,x,sizeof(n) )
#define INF 1 << 30
#define foo(i,j,k) for(int (x)=(i);(x)<(j);(x)+=(k))
#define ffoo(i,j,k) for(int (x)=(i);(x)<=(j);(x)+=(k))


typedef long long LLI;
typedef unsigned long long LLU;

template<class T> T gcd(T x, T y){if (y==0) return x; return gcd(y,x%y);}
template<class T> T lcm(T x, T y){return ((x/gcd(x,y))*y);}
template<class T> T maxt(T x, T y){if (x > y) return x; else return y;}
template<class T> T mint(T x, T y){if (x < y) return x; else return y;}
template<class T> T power(T x, T y){T res=1,a = x; while(y){if(y&1){res*=a;}a*=a;y>>=1;}return res;}
template<class T> T bigmod(T x,T y,T mod){T res=1,a=x; while(y){if(y&1){res=(res*a)%mod;}a=((a%mod)*(a%mod))%mod;y>>=1;}return res;}


int dir[8][2]={{-1,0}
              ,{1,0}
              ,{0,-1}
              ,{0,1}
              ,{-1,-1}
              ,{-1,1}
              ,{1,-1}
              ,{1,1}};


using namespace std;

/*####### Template Ends Here #######*/

struct Card{
    char typ;
    int no;
};

struct Player{
    Card player_card[8];
};

struct Round{
    Card round_card[4];
    int Winner;
};

class Game{
    Player man[4];
    Round rnd[8];
    char Trump;

    public:

        void set_trump(char);
        void set_player_card(int, char*);
        void set_round_card(int, char*);
        void set_round_winner(int, char*);

        void card_draw_debug();
        void round_debug();
};

void Game::set_player_card(int P, char C[]){
    int itr = 0;
    for(int i=0; i<16; i+=2){                   // Total 8 Card for each player P
        man[P].player_card[itr].typ = C[i];
        man[P].player_card[itr++].no = C[i+1] - '0';
    }
}

void Game::set_round_card(int R, char C[]){
    int itr = 0;
    for(int i=0; i<8; i+=2){                    // Each Round R has total 4 cards from ecah player
        rnd[R].round_card[itr].typ = C[i];
        rnd[R].round_card[itr++].no = C[i+1] - '0';
    }
}

void Game::set_trump(char C){
    Trump = C;
}

void Game::set_round_winner(int R, char C[]){
    rnd[R].Winner = C[0] - '0';
}

void Game::card_draw_debug(){
    for(int i=0; i<4; i++){
        cout << "Player : " << i+1 << "\n";
        for(int j=0; j<8; j++){
            cout << "\t Card " << j+1 << " : " << man[i].player_card[j].typ << " - " << man[i].player_card[j].no << "\n";
        }
    }
}

void Game::round_debug(){
    for(int i=0; i<8; i++){
        cout << "Round : " << i+1 << "\n";
        for(int j=0; j<4; j++){
            cout << "\t Player " << j+1 << " Throws : " << rnd[i].round_card[j].typ << " - " << rnd[i].round_card[j].no << "\n";
        }
        cout << "\n\t This Round Winner is -> Player : " << rnd[i].Winner+1 << "\n";
    }
}

int main() {
    #ifdef partho222
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif

    Game g;

    int n;
    char str[30];
    while(cin >> n >> str){
        int l = strlen(str);

        //cout << n << " " << str << endl;
        //cout << l << endl;

        if( l == 8 ){
            g.set_round_card(n, str);
        }
        else if(l == 16){
            g.set_player_card(n, str);
        }
        else if( l == 1){
            g.set_round_winner(n, str);
        }
    }

    g.card_draw_debug();
    g.round_debug();

    return 0;
}
