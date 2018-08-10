#include<iostream>

using namespace std;

//creacion de matriz;
int** CrearMatriz(int size);
void PrintMatriz(int** matrix , int size);
void PrintMatriz(char** matrix , int size);
int** NuevaMatriz(int size,int cord1,int cord2,int** matrix);
int** createMatrix(int n){
        int** retVal = new int*[n];
        for (int i = 0 ; i < n; i++){
                retVal[i] = new int[n];
        }
        return retVal;
}

char** createMatrix2(int n){
        char** retVal = new char*[n];
        for (int i = 0 ; i < n; i++){
                retVal[i] = new char[n];
        }
        return retVal;
}
void freeMatrix(int n,int** matrix){
        for(int i = 0 ; i < n ; i++){
                delete[] matrix[i];
        }
        delete[] matrix;
}
void freeMatrix2(int n,char** matrix){
        for(int i = 0 ; i < n ; i++){
                delete[] matrix[i];
        }
        delete[] matrix;
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
			while(cin.fail()){
				cout<<"Numero no valido porfavor vuelva a intentar"<<endl;
				cin.clear();
				cin.ignore(256,'\n');
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
               		while(cin.fail()){
                                cout<<"Numero no valido porfavor vuelva a intentar"<<endl;
				cin.clear();
				cin.ignore(256,'\n');
                                cin>>matriz;
                        }

			cout<<"Ingrese el segundo numero"<<endl;
			int second = 0;
			cin>>second;
			  while(matriz<0){
                                cout<<"Numero no valido porfavor vuelva a intentar"<<endl;
                                cin>>second;
                        }
			while(cin.fail()){
                                cout<<"Numero no valido porfavor vuelva a intentar"<<endl;
				cin.clear();
				cin.ignore(256,'\n');
                                cin>>matriz;
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
			delete[] numbers;
			PrintMatriz(nueva,size_new);
			int respuesta=0;
			if(size_new==2){
				respuesta = matrix[first][second];
				if((first%2!=0 && second%2!=0) || (first%2==0 && second%2==0)){
					respuesta = respuesta*-1;
				}else{
					respuesta = respuesta*1;
				}
				if(respuesta<0){
				cout<<"Determinante es:-"<<respuesta<<endl;
				}else{
				cout<<"Determinante es:+"<<respuesta<<endl;
				}
			}
			if(size_new==3){
				respuesta = (nueva[0][0]*nueva[1][1]*nueva[2][2]+nueva[0][1]*nueva[1][2]*nueva[2][0]+nueva[0][2]*nueva[1][0]*nueva[2][1])
					-(nueva[2][0]*nueva[1][1]*nueva[0][2]+nueva[2][1]*nueva[1][2]*nueva[0][0]+nueva[2][2]*nueva[2][0]*nueva[0][1]);
				if((first%2!=0 && second%2!=0) || (first%2==0 && second%2==0)){
                                        respuesta = respuesta*-1;
                                }else{
                                        respuesta = respuesta*1;
                                }
				if(respuesta<0){
                                cout<<"Determinante es:-"<<respuesta<<endl;
                                }else{
                                cout<<"Determinante es:+"<<respuesta<<endl;
                                }


			}
			freeMatrix(matriz,matrix);
			freeMatrix(size_new,nueva);	
			




		break;
		       }
		case 2:{
			       char** matriz = createMatrix2(8);
			       for(int a = 0 ; a < 8 ; a++){
			       		for(int b = 0 ; b < 8 ; b++){
						matriz[a][b]='.';
					}
			       }
			       bool movement = false;
			       matriz[3][3] ='*';
			       matriz[4][4] ='*';
			       matriz[3][4] ='$';
			       matriz[4][3] ='$';
			       PrintMatriz(matriz,8);
			       bool win = false;
			       while (win==false){
			       cout<<"Jugador 1 mueva porfavor"<<endl;
			       cout<<"Ingrese coordenada 1"<<endl;
			       int cord1=0;
			       cin>>cord1;
			       cout<<"Ingrese coordenada 2"<<endl;
			       int cord2=0;
			       cin>>cord2;
			       while(cord2>7 || cord1>7){
			       		cout<<"Valores invalidos"<<endl;
					cout<<"Ingrese coordenada 1"<<endl;
	                                cin>>cord1;
					cout<<"Ingrese coordenada 2"<<endl;
					cin>>cord2;

			       }
			       while(matriz[cord1][cord2]=='*' || matriz[cord1][cord2]=='$'){
				       cout<<"Ya hay una pieza ahi porfavor ingrese otra coordenada"<<endl;
				       cout<<"Ingrese coordenada 1"<<endl;
				       cin>>cord1;
				       cout<<"Ingrese coordenada 2"<<endl;
				       cin>>cord2;
			       }
			       while(movement==false){
			       if(matriz[cord1+1][cord2]=='$' || matriz[cord1+1][cord2]=='*'){
				       matriz[cord1][cord2]='*';
				       movement=true;
			       }
			       if(matriz[cord1-1][cord2]=='$' || matriz[cord1-1][cord2]=='*'){
                                       matriz[cord1][cord2]='*';
				       movement=true;
                               }
			       if(matriz[cord1][cord2+1]=='$' || matriz[cord1][cord2+1]=='*'){
                                       matriz[cord1][cord2]='*';
				       movement=true;

                               }if(matriz[cord1][cord2-1]=='$' || matriz[cord1][cord2-1]=='*'){
                                       matriz[cord1][cord2]='*';
				       movement=true;

                               }
			       if(matriz[cord1+1][cord2+1]=='$' || matriz[cord1+1][cord2+1]=='*'){
                                       matriz[cord1][cord2]='*';
				       movement=true;

                               }
			       if(matriz[cord1-1][cord2-1]=='$' || matriz[cord1-1][cord2-1]=='*'){
                                       matriz[cord1][cord2]='*';
				       movement=true;

                               }
			       if(movement==false){
                                        cout<<"Valores invalidos"<<endl;
                                        cout<<"Ingrese coordenada 1"<<endl;
                                        cin>>cord1;
                                        cout<<"Ingrese coordenada 2"<<endl;
                                        cin>>cord2;

                               }


			       }
			       for(int i = 0 ; i < 8 ; i++){
			       		for(int b = 0 ; b < 8 ; b++){
						if(matriz[i][b]=='*'){
							for(int c = i ; c < cord1 ; c++){
								for (int d = b ; b < cord2 ; d++){
									matriz[c][d]='*';
								}
							}
								}
					}
			       }
			       PrintMatriz(matriz,8);
			       cout<<"Jugador 2 mueva porfavor"<<endl;
			       cout<<"Ingrese coordenada 1"<<endl;
			       cin>>cord1;
			       cout<<"Ingrese coordenada 2"<<endl;
			       cin>>cord2;
			       while(cord2>7 || cord1>7){
                                        cout<<"Valores invalidos"<<endl;
                                        cout<<"Ingrese coordenada 1"<<endl;
                                        cin>>cord1;
                                        cout<<"Ingrese coordenada 2"<<endl;
                                        cin>>cord2;
                               }
			       while(matriz[cord1][cord2]=='*' || matriz[cord1][cord2]=='$'){
                                       cout<<"Ya hay una pieza ahi porfavor ingrese otra coordenada"<<endl;
                                       cout<<"Ingrese coordenada 1"<<endl;
                                       cin>>cord1;
                                       cout<<"Ingrese coordenada 2"<<endl;
                                       cin>>cord2;
                               }
			       movement=false;
			       while(movement==false){
                               if(matriz[cord1+1][cord2]=='$' || matriz[cord1+1][cord2]=='*'){
                                       matriz[cord1][cord2]='$';
                                       movement=true;
                               }
                               if(matriz[cord1-1][cord2]=='$' || matriz[cord1-1][cord2]=='*'){
                                       matriz[cord1][cord2]='$';
                                       movement=true;
                               }
                               if(matriz[cord1][cord2+1]=='$' || matriz[cord1][cord2+1]=='*'){
                                       matriz[cord1][cord2]='$';
                                       movement=true;

                               }if(matriz[cord1][cord2-1]=='$' || matriz[cord1][cord2-1]=='*'){
                                       matriz[cord1][cord2]='$';
                                       movement=true;

                               }
                               if(matriz[cord1+1][cord2+1]=='$' || matriz[cord1+1][cord2+1]=='*'){
                                       matriz[cord1][cord2]='$';
                                       movement=true;

                               }
                               if(matriz[cord1-1][cord2-1]=='$' || matriz[cord1-1][cord2-1]=='*'){
                                       matriz[cord1][cord2]='$';
                                       movement=true;

                               }
			       if(movement==false){
			       		cout<<"Valores invalidos"<<endl;
                                        cout<<"Ingrese coordenada 1"<<endl;
                                        cin>>cord1;
                                        cout<<"Ingrese coordenada 2"<<endl;
                                        cin>>cord2;

			       }
				
				
                               }
				PrintMatriz(matriz,8);
				
			       }
			       

			       break;}
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

void PrintMatriz(char** matrix , int size){
	cout<< "   A  B  C  D  E  F  G  H"<<endl;
        for(int i = 0 ; i < size ; i++){
		cout<<i;
                cout<<"|";
                for(int b = 0 ; b < size ; b++){
                        cout<<" "<<matrix[i][b]<<" ";
                }
                cout<<"|"<<endl;
        }

}






