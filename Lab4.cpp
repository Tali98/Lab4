#include<iostream>

using namespace std;

//creacion de matriz;
int** CrearMatriz(int size);
void PrintMatriz(int** matrix , int size);
int** NuevaMatriz(int size,int cord1,int cord2,int** matrix);
int** createMatrix(int n){
        int** retVal = new int*[n];
        for (int i = 0 ; i < n; i++){
                retVal[i] = new int[n];
        }
        return retVal;
}


int main(){
	cout<<"MENU  "<<endl;
	cout<<"1.Ejercicio 1 : COFACTORES"<<endl
	<<"2.Ejercicio 2 : Juego"<<endl;
	cout<<"Ingrese su opcion(en numeros)"<<endl;
	int menu=0;
	cin>>menu;
	switch (menu) {
		case 1:{ 
			cout<<"Ingrese la dimesion de su matriz de orden n"<<endl;
			int matriz = 0;
			cin>>matriz;
			cout<<"SU numero es: "<<endl;
			while(matriz<0){
				cout<<"Numero no valido porfavor vuelva a intentar"<<endl;
				cin>>matriz;	
			}
	
			int** matrix =	createMatrix(matriz);
			        for(int i = 0 ; i < matriz; i++){
			                for(int b = 0 ; b < matriz ; b++){
                       				 matrix[i][b]= rand() % 6 + 1;
        	        	}
        		}
			PrintMatriz(matrix , matriz);
			cout<<"De que posicion desea sacar el cofactor?"<<endl;
			cout<<"Ingrese primer numero"<<endl;
			int first = 0;
			cin>>first;  
			while(matriz<0){
                                cout<<"Numero no valido porfavor vuelva a intentar"<<endl;
                                cin>>first;
                        }
               
			cout<<"Ingrese el segundo numero"<<endl;
			int second = 0;
			cin>>second;
			  while(matriz<0){
                                cout<<"Numero no valido porfavor vuelva a intentar"<<endl;
                                cin>>second;
                        }
			
			int size_new = matriz-1;
			int** nueva = createMatrix(size_new);
			
		       	int nueva_i = 0;
		       	int nueva_b = 0;
			int* numbers = new int[size_new*2];
			int numbers_size=0;
		       	for (int i = 0 ; i < matriz ; i++){
				if(i!=first){
					for(int b = 0 ; b < matriz ; b++){
						if (b!=second){
							numbers[numbers_size]=matrix[i][b];
							numbers_size++;		
						}
					}
				}
			}
			numbers_size=0;
			for(int i = 0 ; i < size_new ; i++){
				for(int b = 0 ; b < size_new ; b++){
					nueva[i][b]=numbers[numbers_size];
					numbers_size++;
				}
			}
						
			PrintMatriz(nueva,size_new);
			int respuesta=0;
			if(size_new==2){
				respuesta = nueva[0][0] * nueva[1][1] - nueva[0][1]*nueva[1][0];
				if((first%2!=0 && second%2!=0) || (first%2==0 && second%2==0)){
					respuesta = respuesta*-1;
				}else{
					respuesta = respuesta*1;
				}
				cout<<"Determinante es: "<<respuesta<<endl;
			}
			
			




		break;
		       }
	}


}



void PrintMatriz(int** matrix , int size){	
	for(int i = 0 ; i < size ; i++){
		cout<<"|";
                for(int b = 0 ; b < size ; b++){
                        cout<<" "<<matrix[i][b]<<" ";
                }
		cout<<"|"<<endl;
        }

}





