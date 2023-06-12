#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

//Esta função exibe o "Modo Usuário"
//Ela é responsável por exibir as opções disponíveis no "Modo Usuário" e serve como um menu para que o usuário escolha o que deseja fazer
void ModoUsuario()
{
    cout << "Modo Usuario" << endl;
    cout << "1 - Listar produtos e precos" << endl;
    cout << "2 - Comprar produto" << endl;
    cout << "3 - Sair" << endl;
}

//Esta função exibe o "Modo Administrador"
//Ela é responsável por exibir as opções disponíveis no "Modo Administrador" e serve como um menu para que o Administrador escolha o que deseja fazer
void ModoAdministrador()
{
    cout << "Modo Administrador" << endl;
    cout << "1 - Repor produtos" << endl;
    cout << "2 - Listar produtos e quantidades" << endl;
    cout << "3 - Verificar total faturado" << endl;
    cout << "4 - Verificar total a faturar" << endl;
    cout << "5 - Sair" << endl;
}

//Função responsável por calcular e exibir o troco a ser devolvido ao cliente, caso o valor inserido seja maior que o valor do produto
void calcularTroco(double valorInserido, double valorProduto)
{
    double troco = valorInserido - valorProduto;

    if (troco > 0)
    {
        cout << "Por favor, retire seu troco de R$ " << fixed << setprecision(2) << troco << endl;
    }
}

//"Classe" para representar a máquina de vendas
//É uma estrutura que encapsula dados e funções relacionadas em um único objeto
//No caso específico, a classe "VendingMachine" é criada para representar uma máquina de venda automática em C++
class VendingMachine
{
private:
    map<string, double> produtos; //Mapa para armazenar produtos e preços
    map<string, int> estoque;     //Mapa para armazenar a quantidade de cada produto em estoque
    double totalFaturado;         //Variável para armazenar o total faturado

public:
    VendingMachine()
    {
        //Inicializa os produtos e estoque
        produtos["Batata Ruffles (100g)"] = 6.00;
        produtos["Batata Lays (100g)"] = 7.00;
        produtos["Doritos (100g)"] = 8.00;
        produtos["Agua S/ Gas (500ml)"] = 3.00;
        produtos["Suco Del Valle Laranja Lata (290ml)"] = 4.00;
        produtos["Coca-Cola Lata (350ml)"] = 5.00;
        produtos["Barra Cereal Chocolate"] = 3.00;
        produtos["Chocolate Kit Kat Tradicional"] = 3.50;
        produtos["Bis Xtra Chocolate"] = 3.50;

        estoque["Batata Ruffles (100g)"] = 5;
        estoque["Batata Lays (100g)"] = 5;
        estoque["Doritos (100g)"] = 5;
        estoque["Agua S/ Gas (500ml)"] = 5;
        estoque["Suco Del Valle Laranja Lata (290ml)"] = 5;
        estoque["Coca-Cola Lata (350ml)"] = 5;
        estoque["Barra Cereal Chocolate"] = 5;
        estoque["Chocolate Kit Kat Tradicional"] = 5;
        estoque["Bis Xtra Chocolate"] = 5;

        totalFaturado = 0.00;
    }

//Esta função listará os produtos e preços
void listarProdutosPrecos()
{
    cout << "Produtos disponiveis:" << endl;
    for (map<string, double>::const_iterator it = produtos.begin(); it != produtos.end(); ++it)
    {
        cout << it->first << " - R$ " << fixed << setprecision(2) << it->second << endl;
    }
}

//Esta função listará os produtos e quantidades em estoque
void listarProdutosQuantidades()
{
    cout << "Produtos em estoque:" << endl;
    for (map<string, int>::const_iterator it = estoque.begin(); it != estoque.end(); ++it)
    {
        cout << it->first << " - Quantidade: " << it->second << endl;
    }
}

//Esta função exibe os produtos
void exibirProdutos(int tipoProduto)
{
    switch (tipoProduto)
    {
    case 1:
        cout << "Opcoes de Snacks:" << endl;
        cout << "1 - Batata Ruffles (100g)" << endl;
        cout << "2 - Batata Lays (100g)" << endl;
        cout << "3 - Doritos (100g)" << endl;
        break;
    case 2:
        cout << "Opcoes de Bebidas:" << endl;
        cout << "1 - Agua S/ Gas (500ml)" << endl;
        cout << "2 - Suco Del Valle Laranja Lata (290ml)" << endl;
        cout << "3 - Coca-Cola Lata (350ml)" << endl;
        break;
    case 3:
        cout << "Opcoes de Doces:" << endl;
        cout << "1 - Barra Cereal Chocolate" << endl;
        cout << "2 - Chocolate Kit Kat Tradicional" << endl;
        cout << "3 - Bis Xtra Chocolate" << endl;
        break;
    default:
        cout << "Tipo de produto invalido." << endl;
        break;
    }
}

//Reposição dos produtos em estoque
void reporProdutos()
{
    int tipoProduto;
    cout << "Digite o tipo de produto a ser reposto ([1] Snacks | [2] Bebidas | [3] Doces): ";
    cin >> tipoProduto;

    switch (tipoProduto)
    {
    case 1:
        exibirProdutos(1);
        break;
    case 2:
        exibirProdutos(2);
        break;
    case 3:
        exibirProdutos(3);
        break;
    default:
        cout << "Opcao invalida." << endl;
        return;
    }

    int opcaoProduto;
    cout << "Digite a opcao do produto: ";
    cin >> opcaoProduto;

    string produto;
    int quantidade;

    switch (tipoProduto)
    {
    case 1:
        switch (opcaoProduto)
        {
        case 1:
            produto = "Batata Ruffles";
            break;
        case 2:
            produto = "Batata Lays";
            break;
        case 3:
            produto = "Doritos";
            break;
        default:
            cout << "Opcao invalida." << endl;
            return;
        }
        break;
    case 2:
        switch (opcaoProduto)
        {
        case 1:
            produto = "Agua S/ Gas";
            break;
        case 2:
            produto = "Suco Del Valle Laranja Lata";
            break;
        case 3:
            produto = "Coca-Cola Lata";
            break;
        default:
            cout << "Opcao invalida." << endl;
            return;
        }
        break;
    case 3:
        switch (opcaoProduto)
        {
        case 1:
            produto = "Barra Cereal Chocolate";
            break;
        case 2:
            produto = "Chocolate Kit Kat Tradicional";
            break;
        case 3:
            produto = "Bis Xtra Chocolate";
            break;
        default:
            cout << "Opcao invalida." << endl;
            return;
        }
        break;
    default:
        cout << "Opcao invalida." << endl;
        return;
    }

    cout << "Digite a quantidade a ser reposta: ";
    cin >> quantidade;

    estoque[produto] += quantidade;

    cout << "Produto(s) reposto(s) com sucesso!" << endl;
}

//A função abaixo realiza a compra
//Será possível pesquisar os produtos pelos nomes parciais
//Também será possível selecionar o modo de pagamento em dinheiro ou cartão
void comprarProduto(const string& produto, double valorInserido)
{
    bool produtoEncontrado = false;

    map<string, double>::const_iterator it;
    for (it = produtos.begin(); it != produtos.end(); ++it)
    {
        const string& nomeProduto = it->first;

        // Verifica se o nome do produto contém o nome parcial fornecido pelo usuário
        if (nomeProduto.find(produto) != string::npos)
        {
            produtoEncontrado = true;

            double valorProduto = it->second;
            int quantidade = estoque[nomeProduto];

            while (valorInserido < valorProduto)
            {
                cout << "Valor inserido insuficiente. Digite '0' para cancelar a compra ou insira o valor correto: ";
                cin >> valorInserido;

                if (valorInserido == 0)
                {
                    cout << "Compra cancelada." << endl;
                    return;
                }
            }

            int opcaoPagamento;
            cout << "Selecione a opcao de pagamento:" << endl;
            cout << "1 - Dinheiro" << endl;
            cout << "2 - Cartao" << endl;
            cout << "Digite a opcao: ";
            cin >> opcaoPagamento;

            if (opcaoPagamento == 1)
            {
                if (quantidade > 0)
                {
                    cout << "Compra realizada com sucesso! Produto: " << nomeProduto << endl;
                    calcularTroco(valorInserido, valorProduto);
                    estoque[nomeProduto] = quantidade - 1;
                    totalFaturado += valorProduto;
                }
                else
                {
                    cout << "Produto indisponivel no momento. Por favor, escolha outro produto." << endl;
                }
            }
            else if (opcaoPagamento == 2)
            {
                if (quantidade > 0)
                {
                    cout << "Compra realizada com sucesso! Produto: " << nomeProduto << endl;
                    estoque[nomeProduto] = quantidade - 1;
                    totalFaturado += valorProduto;
                }
                else
                {
                    cout << "Produto indisponivel no momento. Por favor, escolha outro produto." << endl;
                }
            }
            else
            {
                cout << "Opcao de pagamento invalida." << endl;
                return;
            }

            break;
        }
    }

    if (!produtoEncontrado)
    {
        cout << "Produto invalido. Por favor, escolha um produto valido." << endl;
    }
}

//A função abaixo verifica o total faturado
void verificarTotalFaturado()
    {
        cout << "Total faturado ate o momento: R$ " << fixed << setprecision(2) << totalFaturado << endl;
    }

//A função abaixo verifica o total a faturar
void verificarTotalAFaturar()
{
    double totalAFaturar = 0.00;

    for (map<string, int>::const_iterator it = estoque.begin(); it != estoque.end(); ++it)
    {
        const string& produto = it->first;
        double valorProduto = produtos[produto];
        totalAFaturar += valorProduto * it->second;
    }

    cout << "Total a faturar: R$ " << fixed << setprecision(2) << totalAFaturar << endl;
}

//A função abaixo é responsável por executar o programa
void executar()
    {
        int modo;
        do
        {
            cout << "Escolha o modo de operacao:" << endl;
            cout << "1 - Modo Usuario" << endl;
            cout << "2 - Modo Administrador" << endl;
            cout << "3 - Sair" << endl;
            cout << "Digite uma opcao: ";
            cin >> modo;

            switch (modo)
            {
            case 1:
            {
                int opcaoUsuario;
                do
                {
                    ModoUsuario();
                    cout << "Digite uma opcao: ";
                    cin >> opcaoUsuario;

                    switch (opcaoUsuario)
                    {
                    case 1:
                        listarProdutosPrecos();
                        break;
                    case 2:
                    {
                        string produto;
                        double valorInserido;
                        cout << "Digite o nome do produto: ";
                        cin.ignore();
                        getline(cin, produto);
                        cout << "Digite o valor inserido: ";
                        cin >> valorInserido;
                        comprarProduto(produto, valorInserido);
                        break;
                    }
                    case 3:
                        cout << "Saindo do Modo Usuario." << endl;
                        break;
                    default:
                        cout << "Opcao invalida." << endl;
                        break;
                    }

                    cout << endl;
                } while (opcaoUsuario != 3);

                break;
            }
            case 2:
            {
                string senha;
                while (true)
                {
                    cout << "Digite a senha do administrador: ";
                    cin >> senha;

                    if (senha == "admin123")
                    {
                        break;
                    }

                    cout << "Senha invalida. Por favor, tente novamente!" << endl;
                }

                int opcaoAdministrador;
                do
                {
                    ModoAdministrador();
                    cout << "Digite uma opcao: ";
                    cin >> opcaoAdministrador;

                    switch (opcaoAdministrador)
                    {
                    case 1:
                        reporProdutos();
                        break;
                    case 2:
                        listarProdutosQuantidades();
                        break;
                    case 3:
                        verificarTotalFaturado();
                        break;
                    case 4:
                        verificarTotalAFaturar();
                        break;
                    case 5:
                        cout << "Saindo do modo Administrador." << endl;
                        break;
                    default:
                        cout << "Opcao invalida." << endl;
                        break;
                    }

                    cout << endl;
                } while (opcaoAdministrador != 5);

                break;
            }
            case 3:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
            }

            cout << endl;
        } while (modo != 3);
    }
};

int main()
{
    VendingMachine maquina;
    maquina.executar();

    system("pause");
    
    return 0;
}
