package loja;

import java.util.Scanner;

public class Loja {
    public static void main(String[] args) {
        Scanner leia = new Scanner(System.in);
        produto p1 = new produto(leia.nextLine(), leia.nextLine(), leia.nextDouble(), leia.nextInt());
        leia.nextLine();
        produto p2 = new produto(leia.nextLine(), leia.nextLine(), leia.nextDouble(), leia.nextInt());
        leia.nextLine();
        produto p3 = new produto(leia.nextLine(), leia.nextLine(), leia.nextDouble(), leia.nextInt());
        leia.nextLine();
        produto p4 = new produto(leia.nextLine(), leia.nextLine(), leia.nextDouble(), leia.nextInt());

        Venda venda1 = new Venda(leia.nextLine(), leia.nextLine());
        int a = 1;

        while (a!=0)
        {
            System.out.println("1- Inserir novo produto na venda");
            System.out.println("2-Finalizar compra");
            System.out.println("0-Sair");
             a = leia.nextInt();
            if(a==1)
            {
                System.out.println("----------Produtos--------");
                System.out.println( p1.toString());
                System.out.println( p2.toString());
                System.out.println( p3.toString());
                System.out.println( p4.toString());
                System.out.println("Deseja inserir qual produto?(Código)");
                leia.nextLine();
                String cod = leia.nextLine();
                if(p1.getCodigo().equals(cod))
                {
                    System.out.println("Deseha inserir quantos?");
                    int qtd = leia.nextInt();
                    if(p1.verificaEstoque(qtd)==1)
                    {
                        for(int i=0;i<qtd;qtd++)
                        {
                            venda1.getProdutos().add(p1);
                        }
                        int qtd2 = p1.getEstoque();
                        qtd2-=qtd;
                        p1.setEstoque(qtd2);
                        double total = venda1.getTotal();
                        total+= p1.getPreco() * qtd;
                        venda1.setTotal(total);

                    }

                }
                if(p2.getCodigo().equals(cod))
                {
                    System.out.println("Deseha inserir quantos?");
                    int qtd = leia.nextInt();
                    if(p2.verificaEstoque(qtd)==1)
                    {
                        for(int i=0;i<qtd;qtd++)
                        {
                            venda1.getProdutos().add(p2);
                        }
                        int qtd2 = p2.getEstoque();
                        qtd2-=qtd;
                        p2.setEstoque(qtd2);
                        double total = venda1.getTotal();
                        total+= p2.getPreco() * qtd;
                        venda1.setTotal(total);
                    }

                }
                if(p3.getCodigo().equals(cod))
                {
                    System.out.println("Deseha inserir quantos?");
                    int qtd = leia.nextInt();
                    if(p3.verificaEstoque(qtd)==1)
                    {
                        for(int i=0;i<qtd;qtd++)
                        {
                            venda1.getProdutos().add(p3);
                        }
                        int qtd2 = p3.getEstoque();
                        qtd2-=qtd;
                        p3.setEstoque(qtd2);
                        double total = venda1.getTotal();
                        total+= p3.getPreco() * qtd;
                        venda1.setTotal(total);
                    }

                }
                if(p4.getCodigo().equals(cod))
                {
                    System.out.println("Deseha inserir quantos?");
                    int qtd = leia.nextInt();
                    if(p4.verificaEstoque(qtd)==1)
                    {
                        for(int i=0;i<qtd;qtd++)
                        {
                            venda1.getProdutos().add(p4);
                        }
                        int qtd2 = p4.getEstoque();
                        qtd2-=qtd;
                        p4.setEstoque(qtd2);
                        double total = venda1.getTotal();
                        total+= p4.getPreco() * qtd;
                        venda1.setTotal(total);
                    }

                }
            }
            if(a==2)
            {
                System.out.println("Finalizando a compra...");
                break;
            }
        }
        if(a==2)
        {
            System.out.println(venda1.toString());

        }


    }

}
