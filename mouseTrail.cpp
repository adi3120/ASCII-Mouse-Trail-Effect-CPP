#define s_width 100
#define s_height 60
#include "Fazen.hpp"
#include<vector>
#include<utility>

using namespace std;

int main(){
	Fazen2d game;
    game.make2DConsole(16,16);
	game.background(whiteB);
	
	vector<pair<float,float>> v;
	int n=100;

    while (1)
    {
		game.background(whiteB);

		v.push_back(make_pair(game.Mouse_X(),game.Mouse_Y()));

		if(v.size()>n){
			v.erase(v.begin());
		}
		for(float i=0;i<v.size();i+=1){
			pair<float,float> curr=v[i];
			if(i<n/6)
				game.drawRectangle(curr.first,curr.second,1,1,L'*',0,dmagentaF);
			else if(i<2*(n/6) && i>n/6)
				game.drawRectangle(curr.first,curr.second,2,2,L'*',0,magentaF);
			else if(i<3*(n/6) && i>2*(n/6))
				game.drawRectangle(curr.first,curr.second,2.5,2.5,L'%',0,blueF);
			else if(i<4*(n/6) && i>3*(n/6))
				game.drawCircle(curr.first,curr.second,2,L'$',dgreenF,true,dgreenF);
			else if(i<5*(n/6) && i>4*(n/6))
				game.drawCircle(curr.first,curr.second,3,L'&',dyellowF,true,dyellowF);
			else if(i>5*(n/6))
				game.drawCircle(curr.first,curr.second,4,L'#',redF,true,redF);

			// if(i<n/6)
			// 	game.drawRectangle(curr.first,curr.second,1,1,L'*');
			// else if(i<2*(n/6) && i>n/6)
			// 	game.drawRectangle(curr.first,curr.second,2,2,L'*');
			// else if(i<3*(n/6) && i>2*(n/6))
			// 	game.drawRectangle(curr.first,curr.second,2.5,2.5,L'%');
			// else if(i<4*(n/6) && i>3*(n/6))
			// 	game.drawCircle(curr.first,curr.second,2,L'$',whiteF,true);
			// else if(i<5*(n/6) && i>4*(n/6))
			// 	game.drawCircle(curr.first,curr.second,3,L'&',whiteF,true);
			// else if(i>5*(n/6))
			// 	game.drawCircle(curr.first,curr.second,4,L'#',whiteF,true);
		}
		game.display();

		CHECK_USER_EXIT
    }
}