// Nombre: Carmen Ivonne Turcios Martínez
// Carnet: TM18012
// 

// Librerias a utilizar para el entoro grafico.
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_message.H>
#include <FL/Fl_Round_Button.H>
#include <stdio.h>
#include <string.h>

#define ARCHIVO "clientes.txt" 		// Definición de nombre del archivo, y asignacion de la extensión para el formato de texto.

class Cliente: public Fl_Window 	//Clase 
{ 
	Fl_Input * entrada_Codigo; 		// Definición de atributos a utilizar
	Fl_Input * entrada_Nombre;
	Fl_Input * entrada_Apellido;
	Fl_Input * tx;
	Fl_Round_Button * Bot_guard;
	Fl_Round_Button * Bot_sal;
	Fl_Button * b1.1;
	Fl_Button * b2.1;

	public:
		Cliente() : Fl_Window(600,350)  	// Métodos a utilizar
		{
			begin();
            entrada_Codigo = new Fl_Input(80,20,250,24,"CODIGO:");
            entrada_Nombre = new Fl_Input(80,40,250,24,"NOMBRE:");
            entrada_Apellido = new Fl_Input(80,60,250,24,"APELLIDO:");
			tx = new Fl_Input(80, 100, 0, 0, "GENERO:");
            Bot_guard =  new Fl_Round_Button(100, 80, 40, 40, "F");
            Bot_sal =  new Fl_Round_Button(180, 80, 40, 40, "M");
            b1.1 = new Fl_Button(80,160,100,25,"GUARDAR!");
            b2.1 = new Fl_Button(200,160,100,25,"SALIR!");
            b1.1 -> color(FL_RED);
	       	b2.1 -> color(FL_CYAN);
	     	end();
            b1.1 -> callback(Boton_CB, (void*)this);
            b2.1 -> callback(Boton_CB, (void*)this);
            Bot_guard -> callback(Boton_CB, (void*)this);
            Bot_sal -> callback(Boton_CB, (void*)this);
		} 


		static void Boton_CB(Fl_Widget *w, void *data) 
		{
        	Cliente *cl = (Cliente*)data;

			if ( strcmp(w -> label(), "F") == 0 ) 
			{
      				cl -> SetM(0);
			}

			if( strcmp(w -> label(), "M") == 0 ) 
			{
				cl -> SetF(0);
			}

			if ( strcmp(w -> label(), "GUARDAR") == 0 ) 
			{
				if ( cl -> GUARDAR(ARCHIVO) == 0 ) 
				{     
					fl_message("%s", "datos guardados");       
            	}
				else
				{ 
		         	fl_message("%s", "datos no guardados");
				}
			}

			if ( strcmp(w -> label(), "SALIR") == 0 ) 
			{
				cl -> hide();
			}
 		} 

		int GUARDAR(const char *nom_arch)
		{
			FILE *fp = fopen(nom_arch, "a+");
	
	        if ( !fp ) {
	            fl_message("%s", "ERROR, DIFICULTAD PARA VER EL ARCHIVO");
	            return -1;
			}
	
	         fl_message("%i", Bot_guard -> value());

	      	if( Bot_guard -> value()==0)
			{
				fprintf(fp, "%s %s %s M\n ", entrada_Codigo->value(),entrada_Nombre->value(),entrada_Apellido->value());
	        }

			if( Bot_sal -> value()==0)
	        {
				fprintf(fp, "%s %s %s F\n ", entrada_Codigo->value(),entrada_Nombre->value(),entrada_Apellido->value());
	        }


	      	fclose(fp);
	       	return 0;
		}


		void SetF(int val)      
		{        
	    	Bot_guard -> value(val);
	 	}
	
		void SetM(int val)      
		{        
		    Bot_sal -> value(val);
		}

		void SetCodigo(const char *val)      
		{        
		    entrada_Codigo -> value(val);
		}
 
		const char *GetCodigo() const 
		{ 
			return entrada_Codigo -> value();   
		}

		void SetNombre(const char *val)      
		{        
	    	entrada_Nombre -> value(val);
		}
    
		const char *GetNombre() const 
		{ 
			return entrada_Nombre -> value();   
		}

		void SetApellido(const char *val)      
		{        
	    	entrada_Apellido -> value(val);
		}

		const char *GetApellido() const 
		{ 
			return entrada_Apellido -> value();   
		}
};


int main()  	//Funcion principal
{
     Cliente *e = new Cliente();
     cl -> show();
     return Fl::run();
} 


