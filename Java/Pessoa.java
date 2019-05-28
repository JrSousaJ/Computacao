package classe;

import java.util.Scanner;

public class Pessoa {

	public static void main(String[] args) {
		Scanner leia = new Scanner(System.in);
		Socio s = new Socio(leia.nextLine(),leia.nextLine());
		Dependente k = new Dependente(10, "Joao");
		Dependente k1 = new Dependente(1, "Cleitu");
		Dependente k2 = new Dependente(19, "Sam");
		s.getListaDep().add(k);
		s.getListaDep().add(k1);
		s.getListaDep().add(k2);
		System.out.println(s.toString());
		System.out.println("Quantidade de menores de idade: "+ s.menores());
		System.out.println(s.procura("Caio"));
	}

}
