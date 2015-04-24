/*UTN-FRBA-AED
 * TP Nº 3: Preguntas y Respuestas
 * Alumno: Federico León Bruzone [155-683.6] 
 * Última actualización: 24/04/2015
 */

#include <iostream>
#include<fstream>

std::ifstream fs;
std::string lineap;
std::string linear;
std::string descarte;
int puntaje = 0;
	
void imprimBanner()
{
	using namespace std;

	cout << "\t+---------------------------------+" << endl;
	cout << "\t|Algoritmos y Estructuras de Datos|" << endl;
	cout << "\t|UTN-FRBA-Curso K1051             |" << endl;
	cout << "\t|TP No 3 - Preguntas y Respuestas |" << endl;
	cout << "\t+---------------------------------+\n\n" << endl;
	
}

void abrirArchivo(){
		
	fs.open ("preguntas.txt", std::ifstream::in);
	
	if (fs.is_open()){
		std::cout << "\nArchivo de preguntas cargado.\n" << std::endl;
	} else {
		std::cout << "\nError al abrir el archivo." << std::endl;
	}
	
}


bool recibirRespuesta (){
	bool resp;
	char siono[1];
	
	std::cin.getline(siono, 20);
	if ((siono[0] == 's') || (siono[0] == 'S'))
		resp = 1;
	else { resp = 0;}
return resp;
}

void verificarRespuesta(bool respuesta){
	
	getline (fs, descarte, '#');
	getline (fs, linear, '\n');
	int valorresp = atoi(linear.c_str()); 	// convierte el string proveniente del inputstream a integer
	bool verdaderofalso = valorresp;		// conversion implicita de integer a boolean
		
	if (respuesta == verdaderofalso){
		std::cout << "Muy bien! Su respuesta es correcta.\n" << std::endl;	
		puntaje++;
	} else {
		std::cout << "Lo siento, su respuesta es incorrecta.\n" << std::endl;
	}
}

void preguntarResponderVerificar(){
	bool respuesta;
	int numpreg = 1;
	
	while (getline (fs, lineap, '\t') ){
			std::cout << "Pregunta No " << numpreg << ": ";
			std::cout << lineap;
					
			respuesta = recibirRespuesta();
			verificarRespuesta(respuesta);
			numpreg++;
	}	
}

void mostrarPuntaje(){
	std::cout << "Adios! Su puntaje total es igual a: " << puntaje;	
}

int main() {
		
	using namespace std;
	
	imprimBanner();
	cout << "Bienvenido al juego de preguntas y respuestas.\nEscriba \"Si\" o \"No\" para responder a las preguntas."
	<< "\nPresione una tecla para continuar...";
	cin.get();
	abrirArchivo();
	preguntarResponderVerificar();
	fs.close();
	mostrarPuntaje();
}
