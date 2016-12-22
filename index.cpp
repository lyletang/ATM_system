//2016年c++课程设计
//Name: ATM存取模拟系统
//Author: Jiahui Tang
//Date: 2016-7

#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Clock.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Image.H>
using namespace std;

//---------------------------------------------------
//the global variable

bool user = false; //user is using or no user
string card_ID;
string card_password;
char money[100] = "200";
string text_in;
string text_out;
string text_in1;
string text_in2;
int money_in;
int money_out;
stringstream tmp1;
stringstream tmp3;
string tmp2;
int tmp_before;
int tmp_all;
int password_input_error; //when password input error,the variable +1,
			  //when the variable is 3, the ID locked.
string password_change1;
string password_change2;  //if these two variables are same, change success.

/*
class SimpleWindow : public Fl_Window{
  
	public:
        	SimpleWindow(int w, int h, const char* title );
		~SimpleWindow();
		Fl_Button* copy;
		Fl_Button* quit;
		Fl_Input* inp;
		Fl_Output* out;
		Fl_Text_Display* text;
		Fl_Box* box;	
		Fl_Clock* clock;

	//	Fl_Button* button;
	private:
		static void cb_copy(Fl_Widget*, void*);
		inline void cb_copy_i();
		static void cb_quit(Fl_Widget*, void*);
		inline void cb_quit_i();
};
*/
class GreenButton: public Fl_Button {
	private:
		friend Fl_Button;

		int handle(int e) {
			switch (e)
			{
				case FL_ENTER:
					color(FL_GREEN);
					labelsize(18);
					redraw();
					return 1;
				case FL_LEAVE:
					color(FL_GRAY);
					labelsize(18);
					redraw();
					return 1;
				default: return Fl_Button::handle(e);
			}
		}
	
	public:
		GreenButton(int x, int y, int w, int h, const char* l):Fl_Button(x, y, w, h, l) {}
};

class RedButton: public Fl_Button {
	private:
		friend Fl_Button;	
		int handle(int e) {
			switch (e)
			{
				case FL_ENTER:
					color(FL_RED);
					labelsize(18);
					redraw();
					return 1;
				case FL_LEAVE:
					color(FL_GRAY);
					labelsize(18);
					redraw();
					return 1;
				default: return Fl_Button::handle(e);
			}
		}
	
	public:
		RedButton(int x, int y, int w, int h, const char* l):Fl_Button(x, y, w, h, l) {}
};

class BlueButton: public Fl_Button {
	private:
		friend Fl_Button;
			
		int handle(int e) {
			switch (e)
			{
				case FL_ENTER:
					color(FL_BLUE);
					labelsize(18);
					redraw();
					return 1;
				case FL_LEAVE:
					color(FL_GRAY);
					labelsize(18);
					redraw();
					return 1;
				default: return Fl_Button::handle(e);
			}
		}
	
	public:
		BlueButton(int x, int y, int w, int h, const char* l):Fl_Button(x, y, w, h, l) {}
};

class MagentaButton: public Fl_Button {
	private:
		friend Fl_Button;
			
		int handle(int e) {
			switch (e)
			{
				case FL_ENTER:
					color(FL_MAGENTA);
					labelsize(18);
					redraw();
					return 1;
				case FL_LEAVE:
					color(FL_GRAY);
					labelsize(18);
					redraw();
					return 1;
				default: return Fl_Button::handle(e);
			}
		}
	
	public:
		MagentaButton(int x, int y, int w, int h, const char* l):Fl_Button(x, y, w, h, l) {}
};

class CyanButton: public Fl_Button {
	private:
		friend Fl_Button;
			
		int handle(int e) {
			switch (e)
			{
				case FL_ENTER:
					color(FL_CYAN);
					labelsize(18);
					redraw();
					return 1;
				case FL_LEAVE:
					color(FL_GRAY);
					labelsize(18);
					redraw();
					return 1;
				default: return Fl_Button::handle(e);
			}
		}
	
	public:
		CyanButton(int x, int y, int w, int h, const char* l):Fl_Button(x, y, w, h, l) {}
};

class WhiteButton: public Fl_Button {
	private:
		friend Fl_Button;
			
		int handle(int e) {
			switch (e)
			{
				case FL_ENTER:
					color(FL_WHITE);
					labelsize(18);
					redraw();
					return 1;
				case FL_LEAVE:
					color(FL_GRAY);
					labelsize(18);
					redraw();
					return 1;
				default: return Fl_Button::handle(e);
			}
		}
	
	public:
		WhiteButton(int x, int y, int w, int h, const char* l):Fl_Button(x, y, w, h, l) {}
};

class Window_begin : public Fl_Window {
	
	public:
		

		Window_begin(int w, int h, const char* title);
		~Window_begin();

		Fl_Box* box1;
		Fl_Box* box2;
		Fl_Box* box3;
		Fl_Box* box4;
		Fl_Box* box5;
		Fl_Box* box6;
		Fl_Box* box7;
		Fl_Box* box8;
		Fl_Box* box9;
		Fl_Box* box10;
		Fl_Box* box11;

		Fl_Output* out1;
		Fl_Output* out2;
		Fl_Output* out3;
		Fl_Output* out4;

		Fl_Input* inp1; //bank card ID
		Fl_Input* inp2; //bank card password
		Fl_Input* inp3; //withdraw money
		Fl_Input* inp4; //deposit money
		Fl_Input* inp5; //change password 1
		Fl_Input* inp6; //change password 2

		GreenButton* login; //the user login 
		GreenButton* exit; //the user exit
		RedButton* withdraw; //withdraw money
		MagentaButton* deposit; //deposit money
		WhiteButton* query; //check the balance
		CyanButton* change; //change the password
		RedButton* button1; //withdraw 100
		RedButton* button2; //withdraw 200
		RedButton* button3; //withdraw 300
		RedButton* button4; //withdraw 400
		RedButton* button5; //withdraw 500
		RedButton* button6; //withdraw 800
		RedButton* button7; //withdraw 1000
		RedButton* button8; //withdraw 1500

		Fl_Clock* clock; //the clock

		Fl_Progress* progress; //the progress

		Fl_PNG_Image* image; //the image
	private:
		//the part of the user login and exit
		static void cb_login(Fl_Widget*, void*);
		inline void cb_login_i();

		static void cb_exit(Fl_Widget*, void*);
		inline void cb_exit_i();
		
		//the part of withdraw money
		static void cb_withdraw(Fl_Widget*, void*);
		inline void cb_withdraw_i();

		static void cb_100(Fl_Widget*, void*);
		inline void cb_100_i();
		
		static void cb_200(Fl_Widget*, void*);
		inline void cb_200_i();
		
		static void cb_300(Fl_Widget*, void*);
		inline void cb_300_i();

		static void cb_400(Fl_Widget*, void*);
		inline void cb_400_i();

		static void cb_500(Fl_Widget*, void*);
		inline void cb_500_i();

		static void cb_800(Fl_Widget*, void*);
		inline void cb_800_i();

		static void cb_1000(Fl_Widget*, void*);
		inline void cb_1000_i();

		static void cb_1500(Fl_Widget*, void*);
		inline void cb_1500_i();

		//the part of deposit money
		static void cb_deposit(Fl_Widget*, void*);
		inline void cb_deposit_i();

		//the part of check the balance
		static void cb_query(Fl_Widget*, void*);
		inline void cb_query_i();

		//the part of change password
		static void cb_change(Fl_Widget*, void*);
		inline void cb_change_i();

};


//----------------------------------------------------

int main (int argc, char **argv)
{								   
	
	Window_begin begin(800,600,"ATM!!!");
	return Fl::run();	
	//return 0;	
	//exit(0);
}



Window_begin::~Window_begin(){}

//----------------------------------------------------

/*
SimpleWindow::SimpleWindow(int w, int h, const char* title):Fl_Window(w,h,title)
{		
	begin();			
	copy = new Fl_Button( 10, 150, 70, 30, "C&opy");
	copy->callback( cb_copy, this );	
	quit = new Fl_Button(100, 150, 70, 30, "&Quit");
	quit->callback(cb_quit, this);

	inp = new Fl_Input(50, 50, 140, 30, "Input:");	
	out = new Fl_Output(50, 100, 140, 30);  
	out->value("welcome!");
	box = new  Fl_Box(100,100,260,180,"Hello world");
	box->labelsize(200);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);

	clock = new Fl_Clock(300,300,100,100);

	Fl_Text_Buffer(text);

	end();
	resizable(this);	
	show();
}
*/
//begin window
Window_begin::Window_begin(int w, int h, const char* title):Fl_Window(w, h, title)
{
	begin();

	//const char* name = "image1.png";
	//image->value = new Fl_PNG_Image(name, 100,100); 
	//image = new Fl_PNG_Image(100,100,"image1.png");
	//Fl_PNG_Image("image1.png");
	box10 = new Fl_Box(300,70,200,50,"Author: Jiahui Tang");
	box11 = new Fl_Box(300,100,200,50,"      End of 2016-7");

	box1 = new Fl_Box(300,200,200,50,"Welcome to use the ATM!!!");

	//part of user login
	box1 = new Fl_Box(300,200,200,50,"Welcome to use the ATM!!!");
	box1->labelsize(200);
	box1->labelfont(FL_BOLD+FL_ITALIC);
	box1->labeltype(FL_SHADOW_LABEL);
	inp1 = new Fl_Input(300,250,200,50,"Card  ID:");
	inp2 = new Fl_Input(300,300,200,50,"Password:");
	out1 = new Fl_Output(325,350,150,50);
	out1->value("Please input ID/Password");
	login = new GreenButton(300,400,100,50,"Login");
	login->callback( cb_login, this );	
	exit = new GreenButton(400,400,100,50,"Exit");
	exit->callback( cb_exit, this );

	//part of withdraw money
	box2 = new Fl_Box(0,0,300,50,"Withdraw Money");
	inp3 = new Fl_Input(110,50,100,50,"Any Amount Money:");
	withdraw = new RedButton(230,50,50,50,"Withdraw");
	withdraw->callback( cb_withdraw, this );
	button1 = new RedButton(20,110,50,50,"$100");
	button1->callback( cb_100, this );
	button2 = new RedButton(90,110,50,50,"$200");
	button2->callback( cb_200, this );
	button3 = new RedButton(160,110,50,50,"$300");
	button3->callback( cb_300, this );
	button4 = new RedButton(230,110,50,50,"$400");
	button4->callback( cb_400, this );
	button5 = new RedButton(20,170,50,50,"$500");
	button5->callback( cb_500, this );
	button6 = new RedButton(90,170,50,50,"$800");
	button6->callback( cb_800, this );
	button7 = new RedButton(160,170,50,50,"$1000");
	button7->callback( cb_1000, this ); 
	button8 = new RedButton(230,170,50,50,"$1500");
	button8->callback( cb_1500, this );
	out2 = new Fl_Output(10,230,200,50);
	//out2->value("Single upper limit of 2000,daily limit of 30000.");
	out2->value("Single upper limit of 2000.");

	//part of deposit money
	box3 = new Fl_Box(0,350,300,50,"Deposit Money");
	inp4 = new Fl_Input(100,400,100,50,"Deposit Amount:");
	deposit = new MagentaButton(210,400,50,50,"Deposit");
	deposit->callback( cb_deposit, this );

	//part of check the balance
	box4 = new Fl_Box(0,450,300,50,"Check the balance");
	out3 = new Fl_Output(100,500,100,50,"Your Balance:");
	query = new WhiteButton(210,500,50,50,"Query");
	query->callback( cb_query, this );

	//part of change password
	box5 = new Fl_Box(500,0,300,50,"Change Password");
	inp5 = new Fl_Input(600,50,100,50,"New Password:");
	inp6 = new Fl_Input(600,110,100,50,"Confirm Again:");
	change = new CyanButton(710,50,80,110,"Change");
	change->callback( cb_change, this );
	out4 = new Fl_Output(530,170,260,50);
	out4->value("Continuously enter new password to change");
	box6 = new Fl_Box(530,270,260,50,"Tip: When you login, if you enter error pa");
	box7 = new Fl_Box(530,300,260,50,"ssword three times, your card will be cloc");
	box8 = new Fl_Box(530,330,260,50,"ked.                                      ");
	box9 = new Fl_Box(530,360,260,50,"Mind You!");
	box9->labelsize(200);
	box9->labelfont(FL_BOLD+FL_ITALIC);
	box9->labeltype(FL_SHADOW_LABEL);
	
	//part of other
	clock = new Fl_Clock(585,420,150,150);	
	progress = new Fl_Progress(300,500,200,50,"Speed Of Progess");
	progress->minimum(0);
	progress->maximum(100);
	progress->value(80);
	//tip = new Fl_Output(325,400,150,50);
	//tip->value("Please input ID/password!");
	//inp1 = new Fl_Input(200,200,400,50,"Bank card number:");
	//inp2 = new Fl_Input(200,300,400,50,"Bank card password:");
	//login = new Fl_Button(200,500,400,50,"User Login");
	//login->callback( cb_login, this );	
	
	end();
	resizable(this);
	show();
}

/*
void Window_begin::Window_user() {
	delete box;
	delete inp1;
	delete inp2;
	delete tip;
	delete login;
	button = new Fl_Button(100,100,100,100,"aaaaaa");
	redraw();
}

//-------------------------------------------------											
SimpleWindow::~SimpleWindow(){}

Window_begin::~Window_begin(){}

																//----------------------------------------------------

void SimpleWindow::cb_copy(Fl_Widget* o, void* v) {
																	 
																	    //SimpleWindow* T=(SimpleWindow*)v;
																	       //T->cb_copy_i();
																	          
																		     // or just the one line below
( (SimpleWindow*)v )->cb_copy_i();
																			 }

void SimpleWindow::cb_copy_i() {
	out->value(inp->value()); 
}

//----------------------------------------------------
void SimpleWindow::cb_quit(Fl_Widget* , void* v) {
	( (SimpleWindow*)v )->cb_quit_i();
}

void SimpleWindow::cb_quit_i() {
	hide();
}

void Window_begin::cb_login(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_login_i();
}

void Window_begin::cb_login_i() {
	card_ID = string(inp1->value());
	card_password = string(inp2->value());
	if (card_ID=="abc" && card_password=="123") {

	
	try{
	tip->value("Your ID login success!");
	Window_user();
	//delete inp1;
	//delete inp2;
	//delete box;
	}
	catch(...){}
	//hide();
	redraw();
	//Fl_Widget::damage();
	//SimpleWindow win(800,600,"SimpleWindow");	
	//end();
	//resizable(this);
	//show();
	}
	else {
		tip->value("Your password is worry!");
		//box2 = new Fl_Box(100,400,600,100,"Your password is wrong!");
		redraw();
	}
}
*/
void Window_begin::cb_login(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_login_i();
}

/*
void Window_begin::cb_login_i() {
	for(i=0; i<=100; i++) {
		progress->value(i);
		//sleep(2);
		delay(500);
		redraw();
		}
}
*/

void Window_begin::cb_login_i() {
	if( !user ) {
		card_ID = string(inp1->value());
		card_password = string(inp2->value());
		if (card_ID=="abc" && card_password=="123") {
	
		try{
            
			user = true;
			out1->value(" Your ID login success!");

		}
	
		catch(...) {}
		
		redraw();
		}
		else {
			out1->value("Your password is worry!");
			redraw();
		}
	}
	else {
		out1->value(" One user is using now!");
		
		redraw();
	}
}

void Window_begin::cb_exit(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_exit_i();
}

void Window_begin::cb_exit_i() {	
	//test
	//cout << user << endl;

	if( user ) {
		//exit
		user = false;
		
		//clear the ATM
		inp1->value(""); //clear ID part
		inp2->value(""); //clear password part
		out2->value("Single upper limit of 2000."); //the tip of withdraw
		out3->value(""); //the balance
		out4->value("Continuously enter new password to change"); //change
		
		//the greetings
		out1->value("  Welcome to use again!");
	
		redraw();
	}
	else {
		out1->value("      No user login!");

		redraw();
	}
}

void Window_begin::cb_query(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_query_i();
}

void Window_begin::cb_query_i() {
	if( user ) {
		out3->value(money);
		
		redraw();
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_withdraw(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_withdraw_i();
}

void Window_begin::cb_withdraw_i() {	
	if( user ) {
		text_out = string(inp3->value());
		//money = char*( int(money) + money_in );
		cout << text_out << endl;
		//string -> int	
		tmp1 << text_out;
		tmp1 >> money_out;
		//
		//cout << money_in << endl;

		//string tmp3(money);
		//tmp3 >> tmp_before;
		//tmp_all = tmp_before + money_in;
		//char* -> int
		tmp_before = atoi(money);

		//
		cout << tmp_before << endl;
		tmp_all = tmp_before - money_out;
		cout << tmp_all << endl;

		//itoa(tmp_all, *money, 10);
		//stringstream ss;
		//ss << tmp_all;
		//string pp = ss.str();
		//money = pp.c_str();	
		tmp3 << tmp_all;
		
		const char* temp = tmp3.str().c_str();
		
		cout << temp << endl;
		cout << money << endl;
		cout << endl;
		
		if( money_out <= tmp_before ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
		//clean
		inp3->value("");

		redraw();
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_100(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_100_i();
}

void Window_begin::cb_100_i() {	
	if( user ) {
		int temp_money = 100;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
		
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_200(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_200_i();
}

void Window_begin::cb_200_i() {
	if( user ) {
		int temp_money = 200;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}

}

void Window_begin::cb_300(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_300_i();
}

void Window_begin::cb_300_i() {	
	if( user ) {
		int temp_money = 300;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_400(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_400_i();
}

void Window_begin::cb_400_i() {	
	if( user ) {
		int temp_money = 400;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_500(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_500_i();
}

void Window_begin::cb_500_i() {	
	if( user ) {
		int temp_money = 500;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_800(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_800_i();
}

void Window_begin::cb_800_i() {	
	if( user ) {
		int temp_money = 800;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_1000(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_1000_i();
}

void Window_begin::cb_1000_i() {	
	if( user ) {
		int temp_money = 1000;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_1500(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_1500_i();
}

void Window_begin::cb_1500_i() {
	if( user ) {
		int temp_money = 1500;	
	
		if( money_out <= temp_money ) {
			out2->value("Completed!Please take money!");
			redraw();

			//the active
			}
		else { 
			out2->value("Sorry!Balance is not enough!");
			redraw();
			}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}

void Window_begin::cb_deposit(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_deposit_i();
}

void Window_begin::cb_deposit_i() {	

	if( user ) {
		
		//pass the active of deposit money
		inp4->value("");

		redraw();
	} 
	else {
		out1->value("  Please log in first!");

		redraw();
	}	

}

void Window_begin::cb_change(Fl_Widget*, void* v) {
	( (Window_begin*)v )->cb_change_i();
}

void Window_begin::cb_change_i() {	
	if( user ) {
		text_in1 = string( inp5->value() );
		text_in2 = string( inp6->value() );
		
		if(text_in1 == text_in2) {
			out4->value("Change successful!");

			redraw();
		}
		else {
			out4->value("Change failed!");

			redraw();
		}
	}
	else {
		out1->value("  Please log in first!");

		redraw();
	}
}
