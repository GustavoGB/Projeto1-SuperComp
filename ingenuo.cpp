#include <iostream>
#include <vector>
#include <chrono>
#include <tuple>

using namespace std;

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

void escolhe_alunos(vector<vector<int>> prefs,
                    vector<int> aluno_projeto,
                    vector<int> vagas,
                    tuple<vector<int>, int> &melhor,
                    int i = 0, int satisfacao_atual = 0,
                    bool isNull = false)
{
    if (i == aluno_projeto.size())
    {
        if (isNull == true)
        {
            get<0>(melhor) = aluno_projeto;
            get<1>(melhor) = satisfacao_atual;
            isNull = true;
        }
        if (satisfacao_atual > get<1>(melhor))
        {
            get<0>(melhor) = aluno_projeto;
            get<1>(melhor) = satisfacao_atual;
            isNull = true;
        }
    }

    for (int proj_atual = 0; proj_atual < prefs[1].size(); proj_atual++)
    {
        if (vagas[proj_atual] > 0)
    }
}

int main()
{

    //Receber o input gerado pelo python

    std::cout << "Ola eu sou o bebeto"
              << "\n";
    return 0;
}