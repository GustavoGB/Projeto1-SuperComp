# Projeto1-SuperComp

## O que vamos resolver:

### Estamos tentando resolver um problema que envolve em como alocar um aluno dos ultimos semestres de engenharia em seu projeto final, baseando-se em suas preferencias. Como dito no enunciado, o problema parece simples mas de fato nao e, ja que ele e um problema NP-completo. Isto e, nao existe um metodo que encontra a solucao com maior satisfacao global em tempo polinomial.

### As entradas para o nosso programa terao o seguinte formato:
    
* n_aluno     ->            **representa o numero de alunos** 
* n_projetos     ->            **reprenta o numero de projetos existentes**
* A proxima linha representa as 5 prioridades de um aluno somente
* p1,..,p5       ->  **um numero entre 0 e n_projetos -1, sem repeticoes**

### Ja para as saidas teremos o seguinte formato:
* satisfacao 
* opt  **Optimizacao caso seja 1 e a melhor solucao possivel, 0 caso contrario**
* pa(i) **possui qual projeto o aluno i foi atribuido**

### Como ponto de partida temos uma versao que resolvera o problema em python, nossa primeira tarefa sera traduzir esta versao em uma que seja escrita em C++ e comparar qual a diferenca da velocidade entre estas versoes ingenuas mudando a entrada. 

### Foi assumido que :
* o n_aluno e sempre divisivel por 3 
* n_projeto sempre sera n_alunos/3