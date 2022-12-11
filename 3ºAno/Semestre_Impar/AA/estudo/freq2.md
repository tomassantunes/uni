# Estudo AA Freq 2

### 1.

### 2.

Entre os algoritmos de comité bagging, boosting e stacking existem algumas diferenças. Na abordagem bagging são gerados L conjuntos através do método bootstrap. O método bootstrap tira aleatoriamente, com reposição, N exemplos de um conjunto de treino de tamanho N. Neste caso o método de votação é simples, todos os peritos terão o mesmo peso. Esta estratégia benificia algoritmos instáveis, isto significa que pequenas alterações no conjunto de treino podem provocar grandes diferenças no modelo.

Na estratégia boosting o classificador é treinado com base nos erros dos classificadores anteriores. O algoritmo divide aleatoriamente o conjunto em N conjuntos: X1, X2, ..., XN. No exemplo onde N=3 o algoritmo utiliza X1 para construir p1. Classifica X2 com p1 e utiliza os exemplos mal classificados de X2 para construir p2. Classifica X3 com os peritos p1 e p2. Os exemplos dos quais p1 e p2 discordam são usados para criar p3. Finalmente, cada exemplo de teste é apresentado a p1 e p2. Se concordam, é essa a resposta, se não é a resposta de p3. AdaBoosting é um algoritmo específico de boosting, este algoritmo utiliza sempre o mesmo conjunto, permite usar um número arbitrário de classificadores base e a votação é pesada pelo desempenho de cada classificador base. Há um nível do desempenho que muitas vezes produz melhores classificadores que o bagging mas pode sofrer de sobre-ajustamento.

Por último, a abordagem stacking tem a finalidade de explorar o espaço de modelos diferentes para o mesmo problema, a ideia é atacar o problema usando modelos diferentes em que cada um é capaz de aprender parte do problema, mas não o problema na sua totalidade. Podemos construir modelos diferentes e usá-los para construir uma previsão intermédia. Depois é adicionado um novo modelo que aprende da previsão intermédia. O combinador (modelo criado a partir da previsão intermédia) deve ser treinado com um conjunto de dados não utilizado na construção dos peritos iniciais. 


### 3.

No algoritmo de comité usando um algoritmo de votação existem duas vertentes. Numa primeira abordagem, existe a votação simples onde os peritos têm todos o mesmo peso. E numa segunda abordage, a votação pesada sendo que esta utiliza probabilidades à posteriori para decidir o peso de cada perito (importância da decisão).


### 4.

O algoritmo random forest introduz aleatoriadade no processo de construção das árvores na medida em que interfere na seleção dos subconjuntos de treino utilizados na construção da árvore e na seleção dos atributos no teste de partição. Estas seleções serão aleatórias.  


### 5.

### 6.

2, 3, 5


### 7.

C


### 8.
#### a)

$\frac{47+42+37}{47+42+37+1+2+1+4+7+9}$	= $\frac{126}{150}$ = 0.84

#### b)

Iris-setosa: $\frac{47}{47+1+4}$ = $\frac{47}{52}$ = 0.90

Iris-versicolor: $\frac{42}{42+9+2}$ = $\frac{42}{53}$ = 0.79

Iris-virginica: $\frac{37}{37+7+1}$ = $\frac{47}{45}$ = 0.82

#### c)

$\frac{0.90+0.79+0.82}{3}$ = $\frac{2.51}{3}$ 

#### d)
$\frac{(47+2+1)*0.90}{150}$ + $\frac{(1+42+7)*0.79}{150}$ + $\frac{(4+9+37)*0.82}{150}$ = 0.3 + 0.26 + 0.27 = 0.84


### 9.
#### a)

### 10.
1

### 11.
- Precisão:

    - Cat: $\frac{4}{4+1+1}$ = $\frac{4}{6}$ =  0.67

    - Fish: $\frac{2}{6+2+2}$ = $\frac{2}{10}$ = 0.2

    - Hen: $\frac{6}{3+0+6}$ = $\frac{6}{9}$ = 0.67

- Cobertura:
  
    - Cat: $\frac{4}{4+6+3}$ = $\frac{4}{13}$ =  0.31

    - Fish: $\frac{2}{1+2+0}$ = $\frac{2}{3}$ = 0.67

    - Hen: $\frac{6}{2+1+6}$ = $\frac{6}{9}$ = 0.67

- F1 = Cat: $\frac{2 * precisão * cobertura}{precisão + cobertura}$

    - Cat: $\frac{2 * 0.67 * 0.31}{0.67 + 0.31}$ = $\frac{0.42}{0.98}$ =  0.42

    - Fish: $\frac{2 * 0.2 * 0.67}{0.2+0.67}$ = $\frac{0.27}{0.87}$ = 0.31

    - Hen: $\frac{2*0.67*0.67}{0.67+0.67}$ = $\frac{0.9}{1.34}$ = 0.67

- Macro-média F1:

    - $\frac{0.42+0.31+0.67}{3}$ = $\frac{1.4}{3}$ = 0.47

- Média-ponderada:

    - $\frac{(4+6+3)*0.42}{25}$ + $\frac{(1+2+0)*0.31}{25}$ + $\frac{(1+2+6)*0.67}{25}$ = 0.22 + 0.037 + 0.24 = 0.497

### 12.

F, V, F, F