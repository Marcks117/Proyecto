//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************* Alumno: López Pérez Marcos Emiliano **********//
//*************	Proyecto Final				   			******//
//*************	Microsoft Visaual Studio 2017 			******//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>

#include "cmodel/CModel.h"
//Solo para Visual Studio 2015

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables Carrucel
bool animacionCarrucel = false;
int parametro = 30;
float RotarX = 0.0;
int sol = 0, mercurio = 0, venus = 0;
int tierra = 0, marte = 0, jupiter = 0;


GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };


GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


//NEW// Keyframes
float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;
float giroMonito = 0;
float movBrazoDer = 0.0;

#define MAX_FRAMES 9
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
//	float RotVuelo;
//	float RotVueloInc;
//	float Rotllantitas;
//	float RotllantitasInc;

	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	float movBrazoDer;
	float movBrazoDerInc;

	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=5;			//introducir datos
bool play=false;
bool aquamov = true;      //variable para la animación del agua
int playIndex=0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

//NEW// Keyframes
//Variables de dibujo y manipulacion
//float posX = 0, posY = 5.0, posZ = -3.5, rotRodIzq = 0;
//float giroMonito = 0;
////////Variables animación agua de alberca
float aqua_movX = 0.0;
float aqua_movY = 0.0;
float Ang_ini = 45.0*3.1416 / 180;
float thetha = 0.0;
float thethaX = 0.0;
float thethaY = 0.0;
bool dia = false;
bool noche = false;
bool dia_noche = true;





//Variables Carlos
float MovSi = -5, MovSil = -5, RotLam = 0, MovCor = 95, MovCor1 = 49;
#define MAX_FRAMES 5
//int i_max_steps = 90;
//int i_curr_steps = 0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/



//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture text8; //Loceta del camino

CTexture tree;



CTexture t_madera;
CTexture t_madera1;
CTexture t_madera2;
CTexture t_madera3;
CTexture pasto;
CTexture azulejo;
CTexture azulejo2;
CTexture t_maderab;
CTexture agua1;
CTexture azulejoco;
CTexture maderabl;
CTexture paredcu;
CTexture pisocu;

CTexture piso_cemento;
CTexture piso_bedroom;
CTexture madera_negra;
CTexture textura_llantas;
CTexture textura_madera_base_cama;
CTexture tronco;
CTexture ventana_grande_textura;
CTexture ventana1;
CTexture ventana2;
CTexture ventana_triangulo;
CTexture textPata;
CTexture arco;
CTexture t_puerta_arriba;
CTexture t_puerta_abajo;
CTexture textura_tv;
CTexture negro_brillante;
CTexture madera_blanca;
CTexture piso_cuarto;
CTexture lampara;
CTexture tree1;
CTexture tree2;
CTexture tree3;
CTexture night;
CTexture sun;
CTexture textMet1;
//CTexture azulejo;
///Habitacion Carlos
CTexture Madera;
CTexture texMaNegra;
CTexture textMon;
CTexture textMouse;
//Carteles
CTexture Cartela;
CTexture Cartelb;
CTexture Cartelc;
CTexture Carteld;
CTexture Cartele;
CTexture Cartelf;
CTexture Cartelg;


CModel coche;
CModel sillong;
CModel sillonm;
CModel sillonc;
CModel reloj;
CModel mueble1;
CModel mueble2;
CModel mueble3;
CModel control;
CModel mesa_patio;
CModel sillapatio;




////////////////////////////nombres para las figuras/////////////////////////////////////////////////
CFiguras fig1;
CFiguras fig2;
CFiguras sky;
CFiguras caricatura;
CFiguras techado;


//CFiguras fig1;
//CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito
CFiguras fig8;  //Camino

//Figuras de 3D Studio
CModel kit;
CModel llanta;
CModel casita;
CModel oldhouse;
CModel Dragon;

//Animación del coche

float angRot = 0.0;
float movKitX = 50.0;
float movKitZ = -130.0;
float rotKit = 0.0;
float rotTires = 0.0;
//////////////////////////////////////////////////////////////
float RotVuelo=0.0;
float Rotllantitas=0.0;
float Vuelo=1.0;

bool g_fanimacion = false;
bool g_avanza = false;

bool circuito = false;
bool circuitoR = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;
bool recorrido6 = false;
bool recorrido7 = false;
bool recorrido8 = false;
bool recorrido9 = false;
bool recorrido10 = false; 
bool recorrido11 = false;
bool recorrido12 = false;
bool recorrido13 = false;
bool recorrido14 = false;
bool recorrido15 = false;
bool recorrido16 = false;


//Variables de estados para la animación de vuelo
bool recorridoD = false;
bool recorridoV = false;
bool recorridoA1 = false;
bool recorridoA2 = false;

bool recorridoDR = false;
bool recorridoVR = false;
bool recorridoA1R = false;
bool recorridoA2R = false;


void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
	KeyFrame[FrameIndex].giroMonito = giroMonito;
	KeyFrame[FrameIndex].movBrazoDer = movBrazoDer;

	FrameIndex++;
}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	rotRodIzq = KeyFrame[0].rotRodIzq;
	giroMonito = KeyFrame[0].giroMonito;
	movBrazoDer = KeyFrame[0].movBrazoDer;

}

void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;
	KeyFrame[playIndex].movBrazoDerInc = (KeyFrame[playIndex + 1].movBrazoDer - KeyFrame[playIndex].movBrazoDer) / i_max_steps;

}

void agua()
{
	glPushMatrix();		/// plano1 de animación agua de alberca
	glTranslatef(0, 0, 0);
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, agua1.GLindex);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBegin(GL_POLYGON);
	//glNormal3f(0.0f, 0.0f, 1.0f);	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-55.0 + aqua_movX, -19.5, -100.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-105.0, -19.5 + aqua_movY, -100.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-105.0 + aqua_movX, -19.5, -140.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-55.0, -19.5 + aqua_movY, -140.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-55.0 + aqua_movX, -19.5, -100.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPopMatrix();
}

void ciudad ()
{
	glPushMatrix();
		glPushMatrix(); //Pasto
			glTranslatef(-90.0,0.0,-75.0);
			glScalef(270,0.1,130);
			glDisable(GL_LIGHTING);
			fig4.prisma2(pasto.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //Pasto
		glTranslatef(100.0, -0.002, -37.50);
		glScalef(200, 0.1, 65);
		glDisable(GL_LIGHTING);
		fig4.prisma2(pasto.GLindex, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //Camino central

		glTranslatef(0.0, 0.0, 0.0);
		glScalef(400, 0.1, 20);
		glDisable(GL_LIGHTING);
		fig8.prisma2(azulejo2.GLindex, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,75.0);
			glScalef(400,0.1,130);
			glDisable(GL_LIGHTING);
			fig4.prisma2(pasto.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		glPopMatrix();
}

/////////////Más Pasto////
void jardin(void) {
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0, 0, 170);
	fig1.prisma(0.5, 430, 70, pasto.GLindex);
	glEnable(GL_LIGHTING);

	glPopMatrix();


}

//Carteles
void Carteles(void) {
	glPushMatrix();
	glDisable(GL_LIGHTING);
	//glTranslatef(-65, 0, 40);
	glEnable(GL_ALPHA_TEST);		//Se habilita la transparencia del canal alfa
	glAlphaFunc(GL_GREATER, 0.1);
	fig1.prisma(110, 15, 10.5, Cartela.GLindex);
	glDisable(GL_ALPHA_TEST);		//Se quita la transparencia del canal alfa para la textura
	glEnable(GL_LIGHTING);
	glPopMatrix();

}

//Alberca
void jardin_alberca(void) {
	glPushMatrix();//pasto trasera
	glDisable(GL_LIGHTING);
	glTranslatef(85, 0, -130);
	fig1.prisma(0.5, 90, 20, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//pasto delantero
	glDisable(GL_LIGHTING);
	glTranslatef(85, 0, -70);
	fig1.prisma(0.5, 90, 20, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();//pasto derecho
	glDisable(GL_LIGHTING);
	glTranslatef(120, 0, -100);
	glRotatef(90, 0, 1, 0);
	fig1.prisma(0.5, 50, 20, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();// pasto izquierdo
	glDisable(GL_LIGHTING);
	glTranslatef(50, 0, -100);
	glRotatef(90, 0, 1, 0);
	fig1.prisma(0.5, 50, 20, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///// paredes de alberca

	glPushMatrix();//trasera
	glDisable(GL_LIGHTING);
	//glRotatef(90, 0, 0, 1);
	glTranslatef(85, -5, -120);
	fig1.prisma(10.5, 50, 0.5, azulejo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//delantera
	glDisable(GL_LIGHTING);
	//glRotatef(90, 0, 0, 1);
	glTranslatef(85, -5, -80);
	fig1.prisma(10.5, 50, 0.5, azulejo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();//izquierda
	glDisable(GL_LIGHTING);
	//glRotatef(90, 0, 0, 1);
	glTranslatef(60, -5, -100);
	fig1.prisma(10.5, 0.5, 40, azulejo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//derecha
	glDisable(GL_LIGHTING);
	//glRotatef(90, 0, 0, 1);
	glTranslatef(110, -5, -100);
	fig1.prisma(10.5, 0.5, 40, azulejo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//piso
	glDisable(GL_LIGHTING);
	//glRotatef(90, 0, 0, 1);
	glTranslatef(85, -10, -100);
	fig1.prisma(0.5, 50, 40, azulejo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();		/// plano1 de animación agua de alberca
	glTranslatef(165, 17, 20);
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, agua1.GLindex);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBegin(GL_POLYGON);
	//glNormal3f(0.0f, 0.0f, 1.0f);	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-55.0 + aqua_movX, -19.5, -100.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-105.0, -19.5 + aqua_movY, -100.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-105.0 + aqua_movX, -19.5, -140.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-55.0, -19.5 + aqua_movY, -140.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-55.0 + aqua_movX, -19.5, -100.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-22, 0, -125);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-22, 0, -100);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-47, 0, -100);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-47, 0, -125);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-72, 0, -125);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-72, 0, -100);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();


	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-97, 0, -125);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();//// mueble de jardin mesa
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-97, 0, -100);
	glScalef(.007, .007, .007);
	mesa_patio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();


	glPushMatrix();/// camastro 1
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-50, -19.5, -125);
	glRotatef(270, 0, 1, 0);
	glScalef(.3, .3, .3);
	sillapatio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();


	glPushMatrix();// camastro 2
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-70, -19.5, -125);
	glRotatef(270, 0, 1, 0);
	glScalef(.3, .3, .3);
	sillapatio.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();


	glPushMatrix();// arbusto izquierda
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glPushMatrix();
	glTranslatef(-94, -18.5, -133);
	   	 
}



void arbol_alpha()
{
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable( GL_ALPHA_TEST );
		glAlphaFunc( GL_GREATER, 0.1 );
		glBindTexture(GL_TEXTURE_2D, tree.GLindex);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
				
	glPopMatrix();

	glPushMatrix();
		glRotatef(45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(-45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
		glDisable( GL_ALPHA_TEST );
		glEnable(GL_LIGHTING);
				
	glPopMatrix();
}

void arbol_blend()
{
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);     // Turn Blending On
		//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, tree.GLindex);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();	
	glPopMatrix();

	glPushMatrix();
		glRotatef(45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();	
	glPopMatrix();

	glPushMatrix();
		glRotatef(-45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();				
	glPopMatrix();

	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glBegin(GL_QUADS); //plano
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();		
	glPopMatrix();
	glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);
}

void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
		glScalef(0.5, 0.5, 0.5);
		fig7.prisma(2.0 ,2.0 ,1 ,text2.GLindex);

		glPushMatrix();//Cuello
			glTranslatef(0, 1.0, 0.0);
			fig7.cilindro(0.25, 0.25, 15, 0);
			glPushMatrix();//Cabeza
				glTranslatef(0, 1.0, 0);
				fig7.esfera(0.75, 15, 15, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo derecho-->
			glTranslatef(1.25, 0.65, 0);
			fig7.esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(0.25, 0, 0);
				glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
				glRotatef(-45, 0, 1, 0); 
				glTranslatef(0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo izquierdo <--
			glTranslatef(-1.25, 0.65, 0);
			fig7.esfera(0.5, 12, 12, 0);
			glPushMatrix();
				glTranslatef(-0.25, 0, 0);
				glRotatef(45, 0, 1, 0); 
				glRotatef(25, 0, 0, 1);
				glRotatef(25, 1, 0, 0); 
				glTranslatef(-0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, 0);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//Cintura
			glColor3f(0, 0, 1);
			glTranslatef(0, -1.5, 0);
			fig7.prisma(1, 2, 1, 0);

			glPushMatrix(); //Pie Derecho -->
				glTranslatef(0.75, -0.5, 0);
				glRotatef(-15, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, 0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, 0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, 0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix(); //Pie Izquierdo -->
				glTranslatef(-0.75, -0.5, 0);
				glRotatef(-5, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, 0);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(15+rotRodIzq, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, 0);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, 0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


		glPopMatrix();


		glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}


//Función Que crea una montaña Rusa Mediante Primitivas
void MontañaR_Soporte()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	

	//Vigas Verticales
	glPushMatrix();

	glColor3f(0, 0, 1);
	glTranslatef(0, 10, -15);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 10, 8, 8);
//	glPopMatrix();

//	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(3, 0, 0);
//	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 10, 8, 8);
//	glPopMatrix();

//	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(3, 0, 0);
//	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 10, 8, 8);
//	glPopMatrix();

//	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(3, 0, 0);
//	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 10, 8, 8);

	//	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(3, 0, 0);
	//	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 10, 8, 8);

		glPopMatrix();

		glRotatef(90,0,1,0);
	//Vigas Horizontales
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(15, 2.5, 0);
	glRotatef(-22.5, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 13, 8, 8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(15, 5, 0);
	glRotatef(22.5, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 13, 8, 8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(15, 7.5, 0);
	glRotatef(-22.5, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 6.5, 8, 8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(15, 10, 0);
	glRotatef(22.5, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.1, 13, 8, 8);
	glPopMatrix();
}

void MontañaR_Carril()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();


	//Carril
	glPushMatrix();
//	glColor3f(0, 0, 1);
	glTranslatef(0, 10, -15);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, 0.3, 0.3, 12, 10, 10);
	glPopMatrix();
}
GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	//glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
    //glColor4f(1.0f, 1.0f, 1.0f, 0.5); 
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();
	//-----------------------------------------------------------------
	Cartela.LoadBMP("cartela.bmp");
	Cartela.BuildGLTexture();
	Cartela.ReleaseImage();
	
	night.LoadTGA("texturas/noche.tga");
	night.BuildGLTexture();
	night.ReleaseImage();

	azulejo2.LoadTGA("texturas/azulejo3.tga");
	azulejo2.BuildGLTexture();
	azulejo2.ReleaseImage();

	texMaNegra.LoadTGA("texturas/madera2.tga"); //Textura Madera lisa
	texMaNegra.BuildGLTexture();
	texMaNegra.ReleaseImage();

	sun.LoadTGA("texturas/sun.tga");
	sun.BuildGLTexture();
	sun.ReleaseImage();

	tree1.LoadTGA("texturas/palmera1.tga");
	tree1.BuildGLTexture();
	tree1.ReleaseImage();

	tree2.LoadTGA("texturas/palmera2.tga");
	tree2.BuildGLTexture();
	tree2.ReleaseImage();

	tree3.LoadTGA("texturas/palmera3.tga");
	tree3.BuildGLTexture();
	tree3.ReleaseImage();

	azulejo.LoadTGA("texturas/azulejo.tga");
	azulejo.BuildGLTexture();
	azulejo.ReleaseImage();

	agua1.LoadTGA("texturas/agua.tga");
	agua1.BuildGLTexture();
	agua1.ReleaseImage();

	pasto.LoadTGA("texturas/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	mesa_patio._3dsLoad("modelos3d/mesa_patio.3ds");
	mesa_patio.LoadTextureImages();
	mesa_patio.GLIniTextures();
	mesa_patio.ReleaseTextureImages();

	coche._3dsLoad("modelos3d/coche.3ds");
	coche.LoadTextureImages(),
		coche.GLIniTextures();
	coche.ReleaseTextureImages();


	//---------------------------------------------------------------------
	text2.LoadBMP("logopumas.bmp");
	//text2.LoadBMP("hulkcara.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	textMet1.LoadTGA("texturas/metal1.tga");
	textMet1.BuildGLTexture();
	textMet1.ReleaseImage();


	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	tree.LoadTGA("Tree.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	kit._3dsLoad("kitt.3ds");	
	//kit.VertexNormals();
//Estatua Dragón
	Dragon._3dsLoad("Dragon.3ds");

	llanta._3dsLoad("k_rueda.3ds");

	casita._3dsLoad("Dollshouse.3ds");

	oldhouse._3dsLoad("oldhouse/oldhouse.3ds");
	oldhouse.LoadTextureImages();
	oldhouse.GLIniTextures();
	oldhouse.ReleaseTextureImages();
	
	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	/*for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;
		KeyFrame[i].giroBrazo =0;
		KeyFrame[i].giroBrazoInc = 0;

	}*/

	KeyFrame[0].posX = 0;
	KeyFrame[0].posY = 2.5;
	KeyFrame[0].posZ = -3.5;
	KeyFrame[0].rotRodIzq = 0;
	KeyFrame[0].giroMonito = 0;
	KeyFrame[0].movBrazoDer = 0;

	KeyFrame[1].posX = 20;
	KeyFrame[1].posY = 2.5;
	KeyFrame[1].posZ = -3.5;
	KeyFrame[1].rotRodIzq = 60;
	KeyFrame[1].giroMonito = -90.0;
	KeyFrame[1].movBrazoDer = 40;

	KeyFrame[2].posX = 20;
	KeyFrame[2].posY = 2.5;
	KeyFrame[2].posZ = 4.0;
	KeyFrame[2].rotRodIzq = -20.0;
	KeyFrame[2].giroMonito = 0;
	KeyFrame[2].movBrazoDer = 0;

	KeyFrame[3].posX = 20;
	KeyFrame[3].posY = 2.5;
	KeyFrame[3].posZ = 4.0;
	KeyFrame[3].rotRodIzq = 40.0;
	KeyFrame[3].giroMonito = 45;
	KeyFrame[3].movBrazoDer = 90;

	KeyFrame[4].posX = 20;
	KeyFrame[4].posY = 2.5;
	KeyFrame[4].posZ = 4.0;
	KeyFrame[4].rotRodIzq = -40.0;
	KeyFrame[4].giroMonito = -45;
	KeyFrame[4].movBrazoDer = -90;
	//NEW//////////////////NEW//////////////////NEW//////////////////

}

//Auto para estacionamiento

/*void OtroAuto(void) {

	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(200, 0, 95);
	glScalef(.1, .1, .1);
	coche.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();
	//codigo para cargar auto en cochera 

}*/

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

//Sol que se mueve
void solD(void) {
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0 + thethaX, 40 + thethaY, 0);
	fig1.esfera(10, 50, 50, sun.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

//Función para la musica de fondo

void musiquita(void) {
	PlaySound(TEXT("Feria.wav"), NULL, SND_LOOP|SND_ASYNC);

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	
	glPushMatrix();

	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	
		glPushMatrix();

		//--------------------------------------------------------------------------
		//dibujar carteles
		Carteles();


		//Más pasto
		glPushMatrix();
		glDisable(GL_LIGHTING);
		jardin();
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//Alberca
		glDisable(GL_LIGHTING);
		//glTranslatef(50, -40, 10);
		jardin_alberca();
		glEnable(GL_LIGHTING);
		glPopMatrix();

//		glPushMatrix();//Auto
//		glDisable(GL_LIGHTING);
		//glTranslatef(50, -40, 10);
//		OtroAuto();
//		glEnable(GL_LIGHTING);
//		glPopMatrix();

		//---------------------------------------------------------------------------

//Skybox para animación de día y noche
		if (dia) {


			glPushMatrix(); //MOSTRAMOS CIELO
			glDisable(GL_LIGHTING);
			glTranslatef(0, 60, 0);
			fig1.skybox(430.0, 230.0, 430.0, text1.GLindex);
			solD();
			glEnable(GL_LIGHTING);
			glPopMatrix();
					   			 		  		  		 	  
		}

		if (noche) {

			glPushMatrix(); //MOSTRAMOS CIELO
			glDisable(GL_LIGHTING);
			glTranslatef(0, 60, 0);
			fig1.skybox(430.0, 230.0, 430.0, night.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
		}
		//glPopMatrix();

		


	/*	glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(200.0, 130.0, 140.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();*/

			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					//glScalef(0.5, 0.5, 0.5);
					//monito();
					glCallList(ciudad_display_list);
					glTranslatef(posX, posY, posZ);
					glRotatef(giroMonito, 0, 1, 0);
					glScalef(1.5, 1.5, 1.5);
					monito();
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();


			glPushMatrix(); //Casa M0delo 3ds
			glRotatef(20, 0, 0, 1);
				glTranslatef(-12.0,4,25.0);
				glRotatef(180,0,1,0);
				glScalef(0.3,0.3,0.3);
				casita.GLrender(NULL,_SHADED, 1);
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glScalef(0.3, 0.3, 0.3);				
				glTranslatef(movKitX, Vuelo+4, movKitZ);
				glRotatef(rotKit, 0, 1, 0);

				glRotatef(RotVuelo, 1, 0, 0);

				kit.GLrender(NULL,_SHADED,1.0); //Dibujamos la carroceria
				//llanta.GLrender(NULL,_SHADED,1.0);

				//Colocar aquí las llantas
				glPushMatrix(); //llanta frontal der
					glTranslatef(-6,-1,7.5);
					glRotatef(-rotTires,1,0,0);
					glRotatef(Rotllantitas, 0, 0, 1);
					llanta.GLrender(NULL,_SHADED,1.0);
				glPopMatrix();

				glPushMatrix(); //llanta frontal izq
					glTranslatef(6,-1,7.5);	
					glRotatef(180,0,1,0);
					glRotatef(rotTires,1,0,0);
					glRotatef(Rotllantitas, 0, 0, 1);
					llanta.GLrender(NULL,_SHADED,1.0);
				glPopMatrix();
				
				glPushMatrix(); //llanta trasera der
					glTranslatef(-6,-1,-9.5);	
					glRotatef(-rotTires,1,0,0);
					glRotatef(Rotllantitas, 0, 0, 1);
					llanta.GLrender(NULL,_SHADED,1.0);
				glPopMatrix();

				glPushMatrix(); //llanta trasera izq
					glTranslatef(6,-1,-9.5);	
					glRotatef(180,0,1,0);
					glRotatef(rotTires,1,0,0);
					glRotatef(Rotllantitas, 0, 0, 1);
					llanta.GLrender(NULL,_SHADED,1.0);
				glPopMatrix();

			glPopMatrix();
					
			glPopMatrix();
			//Se dibuja la Montaña Rusa


			//sop
			glPushMatrix();
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			MontañaR_Carril();
			glPopMatrix();
			//sop
				glPushMatrix();
			glTranslatef(24, 0, -30);
			glRotatef(180, 0, 1, 0);
			glScalef(1,1.1,1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(13, 0, 0);
			glScalef(1.1, 1, 1);
			glRotatef(10,0,0,1);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(36, 0, -30);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 1.2, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(28, 2.5, 0);
		//	glRotatef(3, 0, 1, 0);
			glScalef(1.1, 1, 1);
			glRotatef(20, 0, 0, 1);
			MontañaR_Carril();
			glPopMatrix();
//CURVA 1
			//sop
			glPushMatrix();
			glTranslatef(37, 0, -33);
			glRotatef(180, 0, 1, 0);
			glRotatef(30, 0, 1, 0);
			glScalef(0.8, 1.6, 1);
			MontañaR_Soporte();
			glPopMatrix();

			//carr
			glPushMatrix();
			glTranslatef(44, 5.9, -1.8);
			glRotatef(30, 0, 1, 0);
			glScalef(0.8, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(60.0, 7.5, -17.0);
			glRotatef(60, 0, 1, 0);
			glRotatef(35, 0, 0, 1);
			glScalef(0.5, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(38, 0, -39);
			glRotatef(180, 0, 1, 0);
			glRotatef(60, 0, 1, 0);
			glScalef(0.8, 1.9, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(59, 9, -15.50);
			glRotatef(60, 0, 1, 0);
			glScalef(0.8, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(67.0, 11, -29);
			glRotatef(60, 0, 1, 0);
			glRotatef(37, 0, 0, 1);
			glScalef(0.4, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(38, 0, -44);
			glRotatef(180, 0, 1, 0);
			glRotatef(90, 0, 1, 0);
			glScalef(0.8, 2.2, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(68, 12, -34.50);
			glRotatef(90, 0, 1, 0);
			glScalef(0.8, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(67, 17, -54);
			glRotatef(95, 0, 1, 0);
			glRotatef(63, 0, 0, 1);
			glScalef(0.7, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
//////////////////////////////////////////////////////////			
			//sop
			glPushMatrix();
			glTranslatef(54, 0, -70);
			glRotatef(180, 0, 1, 0);
			glRotatef(330, 0, 1, 0);
			glScalef(0.8, 2.9, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(34.0, 19, -48.50);
			glRotatef(300, 0, 1, 0);
			glScalef(0.85, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(65, 0, -55);
			glRotatef(180, 0, 1, 0);
			glRotatef(300, 0, 1, 0);
			glScalef(0.8, 2.9, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(24.0, 23, -56);
			glRotatef(320, 0, 1, 0);
			glRotatef(345, 0, 0, 1);
			glScalef(1.3, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
//////////////////////////////////////////////////////////			
			//sop
			glPushMatrix();
			glTranslatef(0,0,-50);
			glScalef(1, 3.8,1);
			MontañaR_Soporte();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(24, 0, -80);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 3.5, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(38, 42, -50);
			glRotatef(170, 0, 0, 1);
			glScalef(2.1, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(36, 0, -80);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 3.2, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(21, 42, -50);
			glRotatef(120, 0, 0, 1);
			glScalef(2.2, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
//Subida
			//sop
			glPushMatrix();
			glTranslatef(0, 0, -80);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 6, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-12, 50, -50);
			glScalef(1, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
//Bajada
			//sop
			glPushMatrix();
			glTranslatef(-12, 0, -80);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 3, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-21, 64, -50);
			glRotatef(247, 0, 0, 1);
			glScalef(4.55, 1, 1);
			MontañaR_Carril();
			glPopMatrix();

			//sop
			glPushMatrix();
			glTranslatef(-24, 0, -80);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 1, 1);
			MontañaR_Soporte();
			glPopMatrix();

//Aro de la Muerte
			//sop
			glPushMatrix();
			glTranslatef(-36, 0, -80);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 1, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr 1
			glPushMatrix();
			glTranslatef(-60, 0, -50);
			glScalef(2.2, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr 2
			glPushMatrix();
			glTranslatef(-60, 0, -40);
			glScalef(2.2, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(-48, 0, -80);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 1, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr 3
			glPushMatrix();
			glTranslatef(-52, 17, -50);
			glRotatef(135, 0, 0, 1);
			glScalef(1.0, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr 5
			glPushMatrix();
			glTranslatef(-61, 26, -45);
			glRotatef(45, 0, 0, 1);
			glScalef(1.0, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr 4
			glPushMatrix();
			glTranslatef(-57, 12, -51);
			glRotatef(90, 0, 0, 1);
			glRotatef(-20, 0, 1, 0);
			glScalef(1.5, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr 6
			glPushMatrix();
			glTranslatef(-60, 31.5, -45);
			glScalef(1.8, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr 9
			glPushMatrix();
			glTranslatef(-28, 4, -40);
			glRotatef(50, 0, 0, 1);
			glScalef(0.80, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr 7
			glPushMatrix();
			glTranslatef(-49, 37, -45);
			glRotatef(-45, 0, 0, 1);
			glRotatef(-20, 0, 1, 0);
			glScalef(1.0, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr 8
			glPushMatrix();
			glTranslatef(-20, 17, -40);
			glRotatef(90, 0, 0, 1);
			glScalef(1.3, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//sop 
			glPushMatrix();
			glTranslatef(-36, 0, -70);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 1, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(-48, 0, -70);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 1, 1);
			MontañaR_Soporte();
			glPopMatrix();

//Completando la Montaña y estación

//CURVA 2
		
			//sop
			glPushMatrix();
			glTranslatef(-76, 0, -60 );
			glRotatef(180, 0, 1, 0);
			glRotatef(60, 0, 1, 0);
			glScalef(0.8, 1, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-77, 0, -62);
			glScalef(1.4, 1, 1);
			glRotatef(-120, 0, 1, 0);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(-83, 0, -42);
			glRotatef(180, 0, 1, 0);
			glRotatef(90, 0, 1, 0);
			glScalef(0.7, 0.9, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-52.5, 0, -31.5);
			glScalef(1, 1, 1);
			glRotatef(90, 0, 1, 0);
			MontañaR_Carril();
			glPopMatrix();
//////////////////////////////////////////////////////////			
			//sop
			glPushMatrix();
			glTranslatef(-50, 0, -39);
			glRotatef(180, 0, 1, 0);
			glRotatef(330, 0, 1, 0);
			glScalef(0.8, 1, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-75, 0, -18.5);
			glScalef(1, 1, 1);
			glRotatef(-30, 0, 1, 0);
			MontañaR_Carril();
			glPopMatrix();

//TRAMO FINAL
			//sop
			glPushMatrix();
			glTranslatef(-36, 0, -28);
			glRotatef(180, 0, 1, 0);
			glRotatef(320, 0, 1, 0);
			glScalef(1.5, 0.6, 1);
			MontañaR_Soporte();
			glPopMatrix();

			//sop
			glPushMatrix();
			glTranslatef(-34, 0, -30);
			glRotatef(180, 0, 1, 0);
			glScalef(1, 0.1, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(-34, 0, 0);
			glScalef(1.5, 0.1, 1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-4, -5, 0);
			glScalef(2.6, 1, 1);
			glRotatef(60, 0, 0, 1);
			MontañaR_Carril();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-46, -9, 0);
			glScalef(1.8, 1, 1);
			MontañaR_Carril();
			glPopMatrix();
			//sop
			glPushMatrix();
			glTranslatef(-12,0,0);
			glScalef(1.0,1,1);
			MontañaR_Soporte();
			glPopMatrix();
			//carr
			glPushMatrix();
			glTranslatef(-12, 0, 0);
			MontañaR_Carril();
			glPopMatrix();
//ARBOLES
			glPushMatrix();
				glTranslatef(-70, 0, 10);
				arbol_alpha();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-70, 0, -10);
			arbol_alpha();
			glPopMatrix();


//Estatuas dragón
			glPushMatrix();
			glTranslatef(-90, 4, -20);
			glScalef(0.07,0.07,0.07);
			Dragon.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(-90, 4, 20);
			glScalef(0.07, 0.07, 0.07);
			glRotatef(180,0,1,0);
			Dragon.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			//Se dibuja el carrucel Planetario

			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();

			glPushMatrix();
			//glScalef();
			glPushMatrix();
			glTranslatef(60, 2.0, 70);
			glRotatef(RotarX, 1, 0, 0);
			glRotatef(sol, 0.0, 1.0, 0.0);	//La base gira sobre su eje
			glColor3f(1.0, 1.0, 0.0);	// amarillo
			
			glPushMatrix();
			glRotated(90, 1, 0, 0);
			glScalef(1, 1, 0.1);
			glutSolidTorus(24.90, 25,20,20);  //Dibujar la base (radio,H,V);
			glPopMatrix();
			/////////////////////////////////////////
			glPushMatrix();
			glTranslatef(0, 50.0, 0);
			glRotated(-90, 1, 0, 0);
			glutSolidCone(50, 10, 20, 20);
			glTranslatef(0, 0, -55);
			gluCylinder(quadratic, 1, 1, 70, 20, 20);
		
			glPopMatrix();

			glPushMatrix();
			glRotatef(mercurio, 0.0, 1.0, 0.0);	//gira sobre su eje
			glTranslatef(6, 7.0, 0);
			glColor3f(0.64, 0.16456, 0.16278);	//Mercurio
			glRotated(90, 1, 0, 0);
			glScalef(1, 1, 0.1);
			glutSolidTorus(2.3, 2.5, 20,20);
			////////////////////////////////
			glPushMatrix();
			glRotated(0, 1, 0, 0);
			glTranslatef(0, 0, -500);
			gluCylinder(quadratic, 1, 1, 600, 20, 20);

			glPopMatrix();

			glPopMatrix();

			glPushMatrix();
			glRotatef(venus, 0.0, 1.0, 0.0);	//gira sobre su eje
			glTranslatef(15, 7, 0);
			glColor3f(0.90, 0.91, 0.98);	//Venus
			glRotated(90, 1, 0, 0);
			glScalef(1, 1, 0.1);
			glutSolidTorus(2.3, 2.5, 20, 20);
			////////////////////////////////
			glPushMatrix();
			glRotated(0, 1, 0, 0);
			glTranslatef(0, 0, -500);
			gluCylinder(quadratic, 1, 1, 600, 20, 20);

			glPopMatrix();
			//glutSolidSphere(1.5, 14, 14);
			glPopMatrix();

			glPushMatrix();
			glRotatef(tierra, 0.0, 1.0, 0.0);	//gira sobre su eje
			glTranslatef(24, 7, 0);
			glColor3f(0.0, 0.0, 0.7);	//Tierra
			glRotated(90, 1, 0, 0);
			glScalef(1, 1, 0.1);
			glutSolidTorus(2.3, 2.5, 20, 20);
			////////////////////////////////
			glPushMatrix();
			glRotated(0, 1, 0, 0);
			glTranslatef(0, 0, -500);
			gluCylinder(quadratic, 1, 1, 600, 20, 20);

			glPopMatrix();
			//glutSolidSphere(2.0, 14, 14);
			glPopMatrix();

			glPushMatrix();
			glRotatef(marte, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glTranslatef(33, 7, 0);
			glColor3f(3, 0.0, 0.0);	//Marte
			glRotated(90, 1, 0, 0);
			glScalef(1, 1, 0.1);
			glutSolidTorus(2.3, 2.5, 20, 20);
			////////////////////////////////
			glPushMatrix();
			glRotated(0, 1, 0, 0);
			glTranslatef(0, 0, -500);
			gluCylinder(quadratic, 1, 1, 600, 20, 20);

			glPopMatrix();
			//glutSolidSphere(1.6, 14, 14);
			glPopMatrix();
			glPopMatrix();
			/*	glPushMatrix();
				glRotatef(jupiter, 0.0, 1.0, 0.0);	//gira sobre su eje
				glTranslatef(72.0, 0, 0);
				glColor3f(0.8, 0.5, 0.2);	//jupiter
				glutSolidSphere(11.2, 14, 14);  //Draw Jupiter
				glPopMatrix();*/


			glColor3f(1.0,1.0,1.0);

		glPopMatrix(); 

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-11,12.0,-14.0,(void *)font,"Proyecto Final\n Lopez Perez Marcos Emiliano\n Grupo 01");
			//pintaTexto(-11,10.5,-14,(void *)font,"Listas de Dibujo");
			pintaTexto(-11,8.5,-14,(void *)font,s);
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.01;
	fig3.text_der-= 0.01;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;



	//animación agua
	if (aquamov) {
		Ang_ini += .1;
		aqua_movX = cos(Ang_ini);
		aqua_movY = sin(Ang_ini);


	}


	//// animación dia y noche

	if (dia_noche) {

		thetha += 0.005;
		thethaX = 180 * cos(thetha);
		thethaY = 180 * sin(thetha);

		if (thethaY < 0) {
			dia = false;
			noche = true;
		}

		if (thethaY > 0) {
			dia = true;
			noche = false;
		}

	}

	caricatura.text_izq -= 0.001;
	caricatura.text_der -= 0.001;
	if (caricatura.text_izq < -1)
		caricatura.text_izq = 0;
	if (caricatura.text_der < 0)
		caricatura.text_der = 1;


	//Movimiento del coche
	if(g_fanimacion)
	{
		if(g_avanza)
		{
			movKitZ +=1.0;
			rotTires -= 10;
			if(movKitZ>130)
				g_avanza = false;
		}
		else
		{
			movKitZ -=1.0;
			rotTires += 10;
			if(movKitZ<0)
				g_avanza = true;
		}
	}
	if(circuito)
	{
		if(recorrido1)
		{
			rotKit = 0;
			movKitZ ++;
			printf("lolX= %f", movKitZ);
			if(movKitZ>-90)
			{
				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if(recorrido2)
		{
			Rotllantitas = 90;
			Vuelo += 0.60;
			RotVuelo =-35;
			//rotKit = 90;
			movKitZ++;
			printf("lolX= %f", movKitZ);
			if (Rotllantitas = 90)
			{
				Rotllantitas += 1.8;
			}
			if(movKitZ > -42)
			{
				recorrido2 = false;
				recorrido3 = true;
				
			}
		}
		if (recorrido3)
		{
			RotVuelo = 0 ;
			movKitZ++;
			printf("lolX3= %f", movKitZ);
			if (movKitZ > 39)
			{
				recorrido3 = false;
				recorrido4 = true;
			}
		}
			   
		if (recorrido4)
		{
			rotKit = 0;
			Vuelo += 0.10;
			RotVuelo = -10.0;
			movKitZ++;
			printf("lol4= %f", movKitZ);
			if (movKitZ > 73)
			{
				recorrido4 = false;
				recorrido5 = true;
			}
		}

		if (recorrido5)
		{
			RotVuelo = -15.0;
			Vuelo += 0.350;
	//		rotKit = 105;
			movKitZ++;
	//		movKitX = movKitX - 0.41;

			printf("lol5= %f", movKitZ);
			if (movKitZ > 120)
			{
				recorrido5 = false;
				recorrido6 = true;
			}
		}

		if (recorrido6)
		{
			RotVuelo=0.0;
			rotKit = 20;
			movKitZ+=0.4;
			//		movKitX = movKitX - 0.41;
			movKitX +=0.3;
		//	Vuelo+=0.1;
		//	Rotllantitas-=1.8;
			printf("lol6= %f", movKitZ);
			if (movKitZ > 140)
			{
				recorrido6 = false;
				recorrido7 = true;
			}
		}

		if (recorrido7)
		{
			RotVuelo = -15.0;
			Vuelo += 0.5;
			rotKit = 65;
			movKitZ++;
			//		movKitX = movKitX - 0.41;
			movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol7= %f", movKitZ);
			if (movKitZ > 179)
			{
				recorrido7 = false;
				recorrido8 = true;
			}
		}

		if (recorrido8)
		{
			RotVuelo = -15.0;
			Vuelo += 0.5;
			rotKit = 90;
			movKitX++;
			//		movKitX = movKitX - 0.41;
			movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol8= %f", movKitX);
			if (movKitX > 125)
			{
				recorrido8 = false;
				recorrido9 = true;
			}
		}

		if (recorrido9)
		{
			RotVuelo = 0.0;
		//	Vuelo += 0.2;
			rotKit = 90;
			movKitX-=0.6;
			//		movKitX = movKitX - 0.41;
			movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol9= %f", movKitX);
			if (movKitX > 145)
			{
				Vuelo = Vuelo + 1;
				recorrido9 = false;
				recorrido10 = true;
			}
		}

		if (recorrido10)
		{
			RotVuelo = -20.0;
			Vuelo += 0.1;
			rotKit = 120;
			movKitX += 0.4;
			movKitZ -= 0.2;
			//		movKitX = movKitX - 0.41;
		//	movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol10= %f", movKitX);
			if (movKitX > 215)
			{
				recorrido10 = false;
				recorrido11 = true;
			}
		}

		if (recorrido11)
		{
			RotVuelo = -8.0;
			Vuelo += 0.25;
			rotKit = 180;
			movKitZ--;// = 0.6;
			//		movKitX = movKitX - 0.41;
			//movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol11= %f", movKitZ);
			if (movKitZ < 43)
			{
				recorrido11 = false;
				recorrido12 = true;
			}
		}

		if (recorrido12)
		{
			RotVuelo = -62.0;
			Vuelo += 0.79;
			rotKit = 180;
			movKitZ-=0.4;// = 0.6;
			//		movKitX = movKitX - 0.41;
			//movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol12= %f", movKitZ);
			if (movKitZ < 2)
			{
				recorrido12 = false;
				recorrido13 = true;
			}
		}

		if (recorrido13)
		{
			RotVuelo = 0.0;
			//Vuelo += 0.5;
			rotKit = 180;
			movKitZ--;// = 0.6;
			//		movKitX = movKitX - 0.41;
			//movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol13= %f", movKitZ);
			if (movKitZ < -33)
			{
				recorrido13 = false;
				recorrido14 = true;
			}
		}
		if (recorrido14)
		{
			RotVuelo = 0.0;
			//Vuelo += 0.5;
		/*	int Cont=0;
			if (Cont<20)
			{
				rotKit -= 1;
				Cont +=1;
			}*/
			rotKit -= 2.5;
			//movKitZ--;// = 0.6;
			//		movKitX = movKitX - 0.41;
			//movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol14= %f", movKitZ);
			if (rotKit < 135)
			{
				recorrido14 = false;
				recorrido15 = true;
			}
		}
		if (recorrido15)
		{
			RotVuelo = 0.0;
			rotKit += 5;
		//	Vuelo += 0.5;
		//	rotKit = 180;
		//	movKitZ--;// = 0.6;
			//		movKitX = movKitX - 0.41;
			//movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol15= %f", movKitZ);
			if (rotKit > 225)
			{
				recorrido15 = false;
				recorrido16 = true;
			}
		}
		if (recorrido16)
		{
			RotVuelo = -60.0;
			Vuelo += 1;
			rotKit = 180;
			movKitZ-=1.5;// = 0.6;
			//		movKitX = movKitX - 0.41;
			//movKitX++;
			//	Vuelo+=0.1;
			//	Rotllantitas-=1.8;
			printf("lol16= %f", movKitZ);
			if (movKitZ < -250)
			{
				recorrido16 = false;
				recorrido1 = true;
			}
		}

		
		if (animacionCarrucel = true) {
			// Calculate the number of frames per one second:
			//dwFrames++;
			dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
			dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

			//Velocidades de traslación alrededor del sol

			if (dwElapsedTime >= parametro)
			{
				sol = (sol + 1) % 360;
				mercurio = (mercurio + 8) % 360;
				venus = (venus + 7) % 360;
				tierra = (tierra + 6) % 360;
				marte = (marte + 5) % 360;
				jupiter = (jupiter + 4) % 360;
				dwLastUpdateTime = dwCurrentTime;
			}

			glutPostRedisplay();
		}

	}

	//Movimiento del monito
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();
			}
		}
		else
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			i_curr_steps++;
		}

	}

	/*frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}*/

	glutPostRedisplay();
}







void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'O':		//  
		case 'o':
				g_fanimacion^= true; //Activamos/desactivamos la animacíon
				circuito = false;
			break;

		case 'i':		//  
		case 'I':
				circuito^= true; //Activamos/desactivamos la animacíon
				g_fanimacion = false;
				circuitoR ^= false; //Activamos/desactivamos la animacíon
			break;
		case 'x':		//  
		case 'X':
			animacionCarrucel = true; //Activamos/desactivamos la animacíon
			g_fanimacion = false;
			circuitoR ^= false; //Activamos/desactivamos la animacíon
			break;
		case 'r':		//  
		case 'R':
			circuitoR ^= true; //Activamos/desactivamos la animacíon
			circuito ^= true; //Activamos/desactivamos la animacíon
			g_fanimacion = false;
			break;

		case 'k':		//
		case 'K':
			if (FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'l':
		case 'L':
			if (play == false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;

		case 'y':						
		case 'Y':
			posZ++;
			//printf("%f \n", posZ);
			break;

		case 'g':						
		case 'G':
			posX--;
			//printf("%f \n", posX);
			break;

		case 'h':						
		case 'H':
			posZ--;
			//printf("%f \n", posZ);
			break;

		case 'j':						
		case 'J':
			posX++;
			//printf("%f \n", posX);
			break;

		case 'b':						
			rotRodIzq++;
			//printf("%f \n", rotRodIzq);
			break;

		case 'B':						
			rotRodIzq--;
			//printf("%f \n", rotRodIzq);
			break;

		case 'p':						
			giroMonito++;
			//printf("%f \n", giroMonito);
			break;

		case 'P':						
			giroMonito--;
			//printf("%f \n", giroMonito);
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}


void menu(int id)
{

}

int main ( int argc, char** argv )   // Main Function
{
	int submenu;

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (600, 600);	// Tamaño de la Ventana
  glutInitWindowPosition (500, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final Feria"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  musiquita();

  submenu = glutCreateMenu(menuKeyFrame);
  glutAddMenuEntry("Guardar KeyFrame", 0);
  glutAddMenuEntry("Reproducir Animacion", 1);
  glutCreateMenu(menu);
  glutAddSubMenu("Animacion Monito", submenu);

  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop        ( );          // 

  return 0;
}
