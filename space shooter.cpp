#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<string.h>
using namespace std;

int spaceship(int x1,int y1,int x2,int y2,int x3){
		line(x1, y1, x2, y2);  // top to left
	    line(x2, y2,x3, y2);   // left to right
	    line(x3, y2, x1, y1); // right to top
}

int enemy(int x1,int y1,int x2,int y2,int x3){
		line(x1, y1, x2, y2); 	// down to right
	    line(x2, y2,x3, y2);   // right to left
	    line(x3, y2, x1, y1); // left to top
	
}

int Start(){
	initwindow(800,600,"space shooter");
	setcolor(GREEN); // set color green
	settextstyle(EUROPEAN_FONT, HORIZ_DIR ,5); //set font 
	outtextxy(200,200,"Space Shooter"); // set x and y axis and name
	delay(1000); // delay for staying on screen
	cleardevice();
}

int Game_over(){
	initwindow(800,600,"space shooter");
	setcolor(GREEN); // set color green
	settextstyle(EUROPEAN_FONT, HORIZ_DIR ,5); //set font 
	outtextxy(220,210,"Game Over"); // set x and y axis and name
	delay(2000); // delay for staying on screen
	cleardevice();
}
int main()
{
	Start();
	
   initwindow(800,600,"space shooter");

	//spaceship arguments
	int x1 = 351;
	int y1 = 530;
	int x2 = 283;
	int y2 = 591;
	int x3 = 415;
	
	//enemy arguments
 	int enemy_x1 = 100; 
 	int enemy_y1 = 100;
 	int enemy_x2 = 162;
 	int enemy_y2 = 40;
 	int enemy_x3 = 39;
	 
	 //score dispaly
	char str[100];
	int score =0;
 	
	int point = 0;
 	int a = 1;
 	
 	
 	int level = 1;
 	
 	int r = 0;
 	r = rand() % 600;
 	int health = 100;
 	int damage = 50;
 	int speed = 5;	
	int increment = 1;
	while(1)
	{
		cleardevice();
		
		for(int i=0;i<=600;i+=increment){
	

		 //set condition for enemy how times can appear on screen
		enemy(enemy_x1+r,enemy_y1+i,enemy_x2+r,enemy_y2+i,enemy_x3+r);	
		delay(speed);
		cleardevice();
		sprintf(str,"Score: %d",score);
        outtextxy(getmaxx()-100, 10,str);
        sprintf(str,"Enemy Health: %d",health);
        outtextxy(getmaxx()-780, 10,str);
        sprintf(str,"Level: %d",level);
        	outtextxy(getmaxx()-450, 10,str);
		spaceship(x1,y1,x2,y2,x3);
	if(enemy_y1+i == 600 || enemy_y1+i > 600){		
		Game_over();
		exit(1);
	}	
	//seting keys for space ship movement
	if (GetAsyncKeyState(VK_RIGHT)){
		if(x1 <= 770 && x2 <= 770 && x3 <= 770){
			x1+=10;
			x2+=10;
			x3+=10;
		}	
	}
	else if(GetAsyncKeyState(VK_LEFT)){
		if(x1 >= 30 && x2 >= 30 && x3 >= 30){
			x1-=10;
			x2-=10;
			x3-=10;
		}
	}
	else if(GetAsyncKeyState(VK_UP)){
		if(y1 >= 500 && y2 >= 561){
			y1-=10;
			y2-=10;
		}
	}
	else if(GetAsyncKeyState(VK_DOWN)){
		if(y1 <= 520 && y2 <= 581){
			y1+=10;
			y2+=10;
		}
	}
	// press left shift for bullets
	else if(GetAsyncKeyState(VK_SPACE)){
			int bullets = y1;
			
			enemy(enemy_x1+r,enemy_y1+(i+=increment)-1,enemy_x2+r,enemy_y2+(i+=increment)-1,enemy_x3+r);
			while(bullets>=enemy_y1+i){
			circle(x1,bullets-30,5);
			enemy(enemy_x1+r,enemy_y1+(i+=increment)-increment,enemy_x2+r,enemy_y2+(i+=increment)-increment,enemy_x3+r);
			delay(60);
			bullets-=35;
			if((bullets <= enemy_y1+i && bullets >= enemy_y2+i)&&(x1<=enemy_x2+r && x1>=enemy_x3+r )){
				health -=damage;
				if(health == 0){
				point++;
				score++;
			}
			}
			if(point == a){
				if(score >2 && score <=5){
					level = 2;
					if(level == 2){
					damage = 25;
					speed = 3;	
					increment = 2;
					setcolor(GREEN);
					}
					
				}
				if(score > 5)
				{
					level = 3;
					if(level == 3){
						damage = 20;
						speed = 1;
						increment = 3;
						setcolor(BROWN);
					}
					
				}
				r = rand() % 600;
				int enemy_x1 = 100+r; 
			 	int enemy_y1 = 100;
			 	int enemy_x2 = 162+r;
			 	int enemy_y2 = 40;
			 	int enemy_x3 = 39+r;
			 	i=0;
				enemy(enemy_x1,enemy_y1+(i+=increment)-increment,enemy_x2,enemy_y2+(i+=increment)-increment,enemy_x3);
				a++;
				health = 100;
				break;
		}
			cleardevice();
			sprintf(str,"Score: %d",score);
            outtextxy(getmaxx()-100, 10,str);
            sprintf(str,"Enemy Health: %d",health);
        	outtextxy(getmaxx()-780, 10,str);
        	sprintf(str,"Level: %d",level);
        	outtextxy(getmaxx()-450, 10,str);
			spaceship(x1,y1,x2,y2,x3);
			
		}
		}
		delay(speed);
	}
		
	}
	system("pause");
	getch();
	closegraph();
	return 0;
	}

	
