package classe;

import java.util.LinkedList;

public class Socio {
	private String nome, cpf;
	private LinkedList<Dependente> listaDep;
	public String getNome() {
		return nome;
	}
	public Socio(String nome, String cpf)
	{
		this.nome = nome;
		this.cpf = cpf;
		this.listaDep = new LinkedList<>();
	}
	public int menores()
	{
		int i=0;
		for(Dependente k : listaDep)
		{
			if(k.getIdade()<18)i++;
		}
		return i;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String procura(String xx)
	{
		for(Dependente k : listaDep)
		{
			if(xx.equals(k.getNome()))
				return k.Dados();
		}
		return "Nao encontrado\n";
	}
	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	public LinkedList<Dependente> getListaDep() {
		return listaDep;
	}
	public void setListaDep(LinkedList<Dependente> listaDep) {
		this.listaDep = listaDep;
	}
	public String toString()
	{
		String s = "Socio: " + nome + ", " + cpf + "\nDependentes:";
		for(Dependente k : listaDep)
		{
			s+= k.toString() + "\n";
		}
		s+=".\n";
		return s;
	}
}
