package loja;

import java.util.LinkedList;

public class Venda {
    private String data, nomeCli;
    private double total;
    private LinkedList<produto> produtos;

    public Venda(String data, String nomeCli) {
        this.data = data;
        this.nomeCli = nomeCli;
        this.total = 0;
        this.produtos = new LinkedList<produto>();
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public String getNomeCli() {
        return nomeCli;
    }

    public void setNomeCli(String nomeCli) {
        this.nomeCli = nomeCli;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    public LinkedList<produto> getProdutos() {
        return produtos;
    }

    public void setProdutos(LinkedList<produto> produtos) {
        this.produtos = produtos;
    }

    @Override
    public String toString() {
        String aux = "Venda{" +
                "data='" + data + '\'' +
                ", nomeCli='" + nomeCli + '\'' +
                ", total=" + total + " Produtos:\n";
        for (produto k : produtos) {
            aux += k.toString() + '\n';
        }
        return aux;

    }
}
