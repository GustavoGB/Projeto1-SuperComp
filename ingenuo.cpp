#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <sstream>
#include <string>
#include <tuple>
using namespace std;

tuple<vector<int>, int> escolhe_alunos(vector<vector<int>> prefs,
                                       vector<int> aluno_projeto,
                                       vector<int> vagas,
                                       tuple<vector<int>, int> &melhor,
                                       int satisfacao_atual = 0,
                                       bool nulo = false,
                                       int i = 0)
{
    if (i == aluno_projeto.size())
    {
        if (!nulo)
        {
            get<0>(melhor) = aluno_projeto;
            get<1>(melhor) = satisfacao_atual;
            nulo = true;
        }
        if (satisfacao_atual > get<1>(melhor))
        {
            get<0>(melhor) = aluno_projeto;
            get<1>(melhor) = satisfacao_atual;
            nulo = true;
        }
        return melhor;
    }

    for (int itera_projeto = 0; itera_projeto < prefs[1].size(); itera_projeto++)
    {
        if (vagas[itera_projeto] > 0)
        {
            vagas[itera_projeto] -= 1;
            aluno_projeto[i] = itera_projeto;

            melhor = escolhe_alunos(prefs, aluno_projeto, vagas, melhor, satisfacao_atual + prefs[i][itera_projeto], nulo, i + 1);

            aluno_projeto[i] = -1;
            vagas[itera_projeto] += 1;
            nulo = true;
        }
    }
    return melhor;
}

int main()
{

    /*
    1-> Ele pega n_alunos, n_projetos e n_choices e percorre o input com uma 
    compreensao de lista.
    2-> Preenche as prefs com zeros
    3-> Loop percorrendo cada um dos alunos 
    4-> Alocar os projs com outra lista de compreensao splitando o input com um espaco
    5-> Ultimo Loop onde aloca as preferencias conforme o numero de projetos
    6-> Aloca as preferencias baseando-se nas escolhas dos alunos dentro do numero de projetos
    7-> Abre as vagas (3 vagas por projeto)
    8-> Preenche o projeto pra um aluno que nao preencheu ainda 
    9-> Chama a funcao desenvolvida
    10-> Printa os resultados 
    */

    string linha;
    vector<int> entrada, projs;
    int temp, temp_proj;

    // Pegar a entrada do programa ()usar uma func especifica como getline(c/c++)
    getline(cin, linha);
    /* Agora precisamos de uma funcao que nos ajude a parsear a entrada, este link da
    um help https://www.geeksforgeeks.org/stringstream-c-applications/ 
    Com o ss podemos tratar o CIN lido no geline. 
    */
    istringstream ss(linha);

    while (ss >> temp)
    {
        entrada.push_back(temp);
    }

    /* Agora vamos comecar a ler o python com os itens, entao o primeiro item sera falar 
    qual linha da entrada o n_aluno representa, o n_projeto e o n_choices. Como ele pede no
    enunciado a ordem sera respectivamente o que esta dito acima. 
    1 linha:     
    */
    int n_alunos, n_projetos, n_choices;

    n_alunos = entrada[0];
    n_projetos = entrada[1];
    n_choices = entrada[2];
    // Criar o vetor de prefs, 2 Linha
    vector<vector<int>> prefs(n_alunos, vector<int>(n_projetos));
    // Usar o vector pro projs
    // 4
    for (int i = 0; i < n_alunos; i++)
    {

        getline(cin, linha); // pega cada uma das linhas por passagem do for
        istringstream ss(linha);
        projs.clear();
        while (ss >> temp_proj)
        {
            projs.push_back(temp_proj);
        }
        // 5 e 6
        for (int j = 0; j < n_choices; j++)
        {
            prefs[i][projs[j]] = pow(n_choices - j, 2); // altera o vector prefs
        }
    }
    vector<int> vagas(n_projetos, 3);        // 7 Preencher o vetor das vagas
    vector<int> aluno_projeto(n_alunos, -1); // 8 Preencher o vetor com -1

    tuple<vector<int>, int> melhor; // instancia a tupla dnv para poder chamar a funcao feita

    melhor = escolhe_alunos(prefs, aluno_projeto, vagas, melhor);

    cout << get<1>(melhor) << "\n";

    for (auto it = get<0>(melhor).begin(); it != get<0>(melhor).end(); it++)
    {
        cout << *it << "";
    }
    cout << "\n";
}

/* Vamos traduzir o codigo python antigo para C++, para tal vamos replicar a funcao escolhe_aluno
Como recordacao, temos que a escolhe_aluno recebe os seguintes argumentos: 
    * Prefs (preferencia dos alunos)
    * Aluno_projeto()
    * Vagas
    * satisfacao_atual 
    * Melhor 
    * i = 0
*/

/* Quais tipos de dados serao cada um destes argumentos ?
    * Prefs - > vector de int
    * Aluno projeto -> vector de int
    * Vagas - > vector de int 
    * i -> int = 0
    * satisfacao_atual -> int = 0
    * Melhor tupla(vector int, int)  
    * Uma flag caso o melhor caso ja tenha sido encontrado 
*/

/* Quais condicoes e loops temos dentro desta funcao? 
O que eles estao fazendo? Como estao alterando estas estruturas
de dados? 

    * if i == len(aluno_projeto) 
    --> igualar o i para pegar o tamanho dos projetos
    disponiveis para os alunos. C++ podemos usar o .size ja que 
    queremos sabe o tamanho do Vetor!
    i == aluno_projeto.size() 
    * std::cout << "(" << std::get<0>(t) << ", " << std::get<1>(t) -> (Exemplo tupla)
*/