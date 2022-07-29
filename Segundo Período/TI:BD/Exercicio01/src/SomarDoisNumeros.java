import java.util.*;
class SomarDoisNumeros {
	public static Scanner sc= new Scanner (System.in);
	
	public static void main (String args[]) {
		// Declaração das variáveis
		int numero1, numero2, resultado;
		
		//Leitura dos números
		System.out.println("Digite um número:");
		numero1=sc.nextInt();
		System.out.println("Digite outro número:");
		numero2=sc.nextInt();
		
		//Soma
		resultado=numero1+numero2;
		
		//Mostrar na tela
		System.out.println("O resultado da soma corresponde à: "+ resultado);
	}
}
