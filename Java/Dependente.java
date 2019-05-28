package classe;

public class Dependente {
	private int idade;
	private String nome;
	
	public Dependente(int idade, String nome) {
		this.idade = idade;
		this.nome = nome;
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	public String getNome() {
		return nome;
	}
	public String Dados()
	{
		return "Nome: " + nome + "\nIdade: " + idade;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	@Override
	public String toString() {
		return nome + ", " + idade;
	}
}
