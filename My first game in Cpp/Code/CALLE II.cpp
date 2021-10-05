#include <iostream>
#include <windows.h>
#include <conio.h>
void gotoxy(int x,int y){//Simulacion de la funcion gotoxy
HANDLE hCon;hCon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;dwPos.X=x;dwPos.Y=y;SetConsoleCursorPosition(hCon,dwPos);	
}
void OcultarCursor(){ //Esta estructura solo es estetica, retira la aparicion del cursor de la pantalla...
HANDLE hCon;hCon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci;cci.dwSize = 10;
cci.bVisible = FALSE;SetConsoleCursorInfo(hCon,&cci);
}
void info_unach(){
system("cls");system("color F1");
gotoxy(0,4);printf("GRACIAS POR JUGAR!!!");Sleep(10);	

gotoxy(0,6);printf("|O| Nombre de la universidad: Universidad Autonoma de Chiapas");Sleep(10);	
gotoxy(0,7);printf("|O| Carrera: Ingenieria En Desarrollo y Tecnologias de Software");Sleep(20);
gotoxy(0,8);printf("|O| Facultad: Contaduria y Administracion C-I");Sleep(30);
gotoxy(0,9);printf("|O| Materia: Programacion Estructurada");Sleep(40);
gotoxy(0,10);printf("|O| Nombre del docente: Octavio Florentino Garcia Narcia");Sleep(50);
gotoxy(0,11);printf("|O| Nombre y numero del equipo: ABC Eq-7");Sleep(60);
gotoxy(0,12);printf("|O| integrantes del equipo: +Jose Gilberto Guzman Gutierrez");Sleep(70);
gotoxy(28,13);printf("+Alexis Johesio Solis Utrilla");Sleep(80);
gotoxy(28,14);printf("+Leonardo Hilerio Gutierrez");Sleep(90);
gotoxy(0,15);printf("|O| Semestre y grupo: 1N");Sleep(100);
gotoxy(0,16);printf("|O| Fecha y lugar de entrega: 27/11/2020");Sleep(110);
printf("\n\n\n\n\n\n\n\n");
}
void menu_letras(){
	for(int h=5;h<15;h++){//Todos los ciclos for que veras a continuacion...
	system("color F2");gotoxy(h,6);printf("%c",216);Sleep(60);//Son unicamente animaciones del menu
	}
	for(int h=6;h<12;h++){
	gotoxy(5,h);printf("%c",216);Sleep(60);
	}
	for(int h=5;h<15;h++){
	gotoxy(h,12);printf("%c",216);Sleep(40);
	}
	for(int h=6;h<13;h++){
	system("color 14");gotoxy(17,h);printf("%c",216);Sleep(40);
	}
	for(int h=18;h<25;h++){
	gotoxy(h,6);printf("%c",216);Sleep(40);
	}
	for(int h=6;h<13;h++){
	gotoxy(25,h);printf("%c",216);Sleep(40);
	}
	for(int h=18;h<25;h++){
	gotoxy(h,9);printf("%c",216);Sleep(40);
	}
	for(int h=6;h<13;h++){
	system("color 07");gotoxy(28,h);printf("%c",216);Sleep(40);
	}
	for(int h=29;h<34;h++){
	gotoxy(h,12);printf("%c",216);Sleep(40);
	}
	for(int h=6;h<13;h++){
	system("color A5");gotoxy(36,h);printf("%c",216);Sleep(40);
	}
	for(int h=37;h<42;h++){
	gotoxy(h,12);printf("%c",216);Sleep(40);
	}	
	for(int h=6;h<13;h++){
	system("color FB");gotoxy(44,h);printf("%c",216);Sleep(40);
	}
	for(int h=44;h<52;h++){
	gotoxy(h,6);printf("%c",216);Sleep(50);
	}
	for(int h=44;h<52;h++){
	gotoxy(h,9);printf("%c",216);Sleep(50);
	}
	for(int h=44;h<52;h++){
	gotoxy(h,12);printf("%c",216);Sleep(50);
	}
	for(int h=56;h<67;h++){
	system("color 0E");gotoxy(h,6);printf("%c",216);Sleep(50);
	}
	for(int h=7;h<12;h++){
	gotoxy(58,h);printf("%c",216);Sleep(50);
	}
	for(int h=7;h<12;h++){
	gotoxy(64,h);printf("%c",216);Sleep(50);
	}
	for(int h=56;h<67;h++){
	gotoxy(h,12);printf("%c",216);Sleep(50);
	}
}
void pintar_limites(){//Dibujo del marco 
	for(int h=15;h<65;h++){//Lineas paralelas horizontales
		gotoxy(h,5);printf("%c",205);gotoxy(h,20);printf("%c",205);
	}
	for(int h=5;h<20;h++){//Lineas paralelas verticales 
		gotoxy(15,h);printf("%c",186);gotoxy(65,h);printf("%c",186);
	}
	gotoxy(15,5);printf("%c",201);//Esquina 1 del marco
	gotoxy(15,20);printf("%c",200);//Esquina 2 del marco
	gotoxy(65,5);printf("%c",187);//Esquina 3 del marco
	gotoxy(65,20);printf("%c",188);//Esquina 4 del marco
}
class JUGADOR{
	int x, y;public:
	JUGADOR(int _x,int _y);//contructor de la clase
	void pintar() const;void borrar() const;
	void Y(int _y){y+=_y;}void X(int _x){x+=_x;}
	int RY(){return y;}int RX(){return x;}
};	
JUGADOR::JUGADOR(int _x, int _y){
x=_x; y=_y;
}
void JUGADOR::pintar() const{
gotoxy(x,y);printf("\033[0;34m");printf("%c",190);//Jugador
}
void JUGADOR::borrar() const{
gotoxy(x,y);printf(" ");
}
class RECTANGULO{
	int x,y;int dx, dy;public:
	RECTANGULO(int _x, int _y,int _dx,int _dy);
	void pintar() const;void borrar() const;
	void mover(JUGADOR A);int RY(){return y;}
	int RX(){return x;}
};
RECTANGULO::RECTANGULO(int _x,int _y,int _dx,int _dy):x(_x),y(_y),dx(_dx),dy(_dy){}
void RECTANGULO::pintar() const{//automovil 
	 gotoxy(x-1,y);printf("\033[0;33m");printf("0");
	 gotoxy(x,y);printf("\033[0;33m");printf("%c",223);
	 gotoxy(x+1,y);printf("\033[0;33m");printf("0");
}
void RECTANGULO::borrar() const{
	 gotoxy(x-1,y);printf(" ");gotoxy(x,y);printf(" ");gotoxy(x+1,y);printf(" ");
}
void RECTANGULO::mover(JUGADOR A){
borrar();x+=dx;pintar();
	if(x+dx==16 || x+dx==64){
	borrar();dx=-dx;
}
}
using namespace std;
int audio1()//Estos comandos igualmente son esteticos unicamente reproducen la musica 
{
char soundfile[] = "C:/fondo.wav";PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
}
int audio2()
{
char soundfile[] = "C:/choque.wav";PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
}
int audio3()
{
char soundfile[] = "C:/victoria.wav";PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
}
int audio4()
{
char soundfile[] = "C:/intro.wav";PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
}
int audio5()
{
char soundfile[] = "C:/final.wav";PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
}
int main(){
	audio4();menu_letras();
	int opc;
	gotoxy(0,15);printf("Para iniciar el juego ingresa el numero 1,\nde caso contrario la aplicacion se cerrara.");
	char opcion;scanf("%d",&opcion);
	if(opcion==1){
	int nivel;gotoxy(0,17);	printf("Que nivel quieres jugar? del 10 al 1: ");
	scanf("%d",&nivel);
	do{
	audio1();
	int a=1;system("cls");OcultarCursor();pintar_limites();JUGADOR A(40,19);
	RECTANGULO P1(20,7,1,1);RECTANGULO P2(25,8,1,1);RECTANGULO P3(30,9,1,1);
	RECTANGULO P4(35,10,1,1);RECTANGULO P5(40,11,1,1);RECTANGULO P6(45,12,1,1);
	RECTANGULO P7(50,13,1,1);RECTANGULO P8(55,14,1,1);RECTANGULO P9(60,15,1,1);
	RECTANGULO P10(55,16,1,1);RECTANGULO P11(50,17,1,1);RECTANGULO P12(45,18,1,1);
	A.pintar();char tecla;int cont=0;
	while(A.RY()!=6){
		A.pintar();
		if(kbhit()){
			A.borrar();
			tecla=getch();	
			if(tecla == 72 and A.RY()>6){//tecla arriba
				A.Y(-1);
			}
			else if(tecla == 80 and A.RY()<19){//tecla abajo
				A.Y(1);
			}
			else if(tecla == 75 and A.RX()>16){//tecla izquierda
				A.X(-1);
			}
			else if(tecla == 77 and A.RX()<64){//tecla derecha
				A.X(1);
			}
			A.pintar();
		}
		if(!cont++)
		{
		  P1.mover(A);P2.mover(A);P3.mover(A);
		  P4.mover(A);P5.mover(A);P6.mover(A);
		  P7.mover(A);P8.mover(A);P9.mover(A);
		  P10.mover(A);P11.mover(A);P12.mover(A);
	    }
		if(cont>nivel)cont=0;
		if((P1.RX()==A.RX()&&P1.RY()==A.RY())or(P1.RX()+1==A.RX()&&P1.RY()==A.RY())or(P1.RX()-1==A.RX()&&P1.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P2.RX()==A.RX()&&P2.RY()==A.RY())or(P2.RX()+1==A.RX()&&P2.RY()==A.RY())or(P2.RX()-1==A.RX()&&P2.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P3.RX()==A.RX()&&P3.RY()==A.RY())or(P3.RX()+1==A.RX()&&P3.RY()==A.RY())or(P3.RX()-1==A.RX()&&P3.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P4.RX()==A.RX()&&P4.RY()==A.RY())or(P4.RX()+1==A.RX()&&P4.RY()==A.RY())or(P4.RX()-1==A.RX()&&P4.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P5.RX()==A.RX()&&P5.RY()==A.RY())or(P5.RX()+1==A.RX()&&P5.RY()==A.RY())or(P5.RX()-1==A.RX()&&P5.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P6.RX()==A.RX()&&P6.RY()==A.RY())or(P6.RX()+1==A.RX()&&P6.RY()==A.RY())or(P6.RX()-1==A.RX()&&P6.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P7.RX()==A.RX()&&P7.RY()==A.RY())or(P7.RX()+1==A.RX()&&P7.RY()==A.RY())or(P7.RX()-1==A.RX()&&P7.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P8.RX()==A.RX()&&P8.RY()==A.RY())or(P8.RX()+1==A.RX()&&P8.RY()==A.RY())or(P8.RX()-1==A.RX()&&P8.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P9.RX()==A.RX()&&P9.RY()==A.RY())or(P9.RX()+1==A.RX()&&P9.RY()==A.RY())or(P9.RX()-1==A.RX()&&P9.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P10.RX()==A.RX()&&P10.RY()==A.RY())or(P10.RX()+1==A.RX()&&P10.RY()==A.RY())or(P10.RX()-1==A.RX()&&P10.RY()==A.RY())){
			audio2();a=0; break;
		}
		if((P11.RX()==A.RX()&&P11.RY()==A.RY())or(P11.RX()+1==A.RX()&&P11.RY()==A.RY())or(P11.RX()-1==A.RX()&&P11.RY()==A.RY())){
			audio2();a=0; break;
		}	
		if((P12.RX()==A.RX()&&P12.RY()==A.RY())or(P12.RX()+1==A.RX()&&P12.RY()==A.RY())or(P12.RX()-1==A.RX()&&P12.RY()==A.RY())){
			audio2();a=0; break;
		}
		Sleep(15);	
	}
	if(a==0)
		{gotoxy(37,22);printf("Perdiste");}
	else
	{audio3();gotoxy(37,22);printf("Ganaste");nivel=nivel-2;}
	gotoxy(37,24);printf("Quieres seguir jugando? 1:SI 2:NO= ");scanf("%d",&opc);
}while(opc==1);
 }
audio5();info_unach();
return 0;
}
