# Apontamentos Aprendizagem Automática

## Iris

Este dataset contém medidas associadas às flores Iris: o comprimento e a largura das pétalas e das sépalas, todas em centímetros. Também contém as medições de algumas iris das espécies: *setosa*, *versicolor* e *virginica*.

## Meet the Data

Este dataset está incluído no **scikit-learn** no módulo **datasets**. Podemos carregá-lo chamando o método **load_iris**:

```python
from sklearn.datasets import load_iris
iris = load_iris()
``` 
O objecto que é retornado é um objecto Bunch que é similar a uma lista. Contém chaves e valores:

```python
print("iris keys: \n {}".format(iris.keys()))
``` 

## Training and Testing Data

Queremos construir um modelo de ML com estes dados, de modo a que este consiga adivinhar a espécie de iris para um novo conjunto de medidas. Mas antes temos de saber se o modelo funciona.

Não podemos usar os mesmos dados, para todos os testes, pois o modelo pode simplesmente memorizar os dados, tendo assim uma taxa de previsão de 100%.

**train_test_split** -> Extrai 75% das linhas de 'data' como set de treino, e os restantes 25% são declarados como set de teste.

```python
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(iris['data'], iris['traget'], random_state=0)
``` 
Antes de fazer o split a função **train_test_split** mistura os dados do dataset.

## Look at Your Data

Antes de contruir um modelo de ML é uma boa ideia inspecionar os dados, para perceber se a tarefa é facilmente resolvida sem ML.

Adicionalmente, inspecionar os dados é uma boa forma de encontrar anomalias e peculariadades.

Uma das melhores forma de inspecionar dados é vê-los. Uma das maneiras de fazer isso é usando o *scatter plot*. Este põe os dados num gráfico 2D, dividindo-os pelo eixo do x e do y, e desenha um ponto por cada ponto de dados.

```python
import pandas as pd
iris_dataframe = pd.DataFrame(X_train, columns=iris.feature_names)
grr = pd.scatter_matrix(iris, c=y_train, figsize(15, 15), marker='o', hist_kwds{'bins', 20}, s=60, alpha=.8, cmap=mglearn.cm3)
```

## k-Nearest Neighbors

O k em k-Nearest Neighbors quer dizer que, em vez de apenas considar o vizinho mais próximo de certo ponto, podemos considerar os k vizinhos mais próximos desse ponto.

```python
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors=1)
```

Para construir o set de treino, podemos chamar o método **fit** do objecto knn:

```python
knn.fit(X_train, y_train)
```

O método fit retorno o objecto knn, e modifica-o para termos uma string representativa do classificador.

## Fazer previsões

Podemos usar este modelo para fazer previsões sobre dados novos para os quais podemos não saber as designações corretas. Imaginemos que se encontra uma Iris, a que espécie pertencerá esta? Fazemos as medições da mesma, pomos os dados num NumPy array e depois fazemos a previsão.

```python
X_new = np.array([[5, 2.9, 1, 0.2]])
print("X_new.shape: {}".format(X_new.shap))
```

Para fazer uma previsão chamamaos o método *predict* do objecto knn:
```python
prediction = knn.predict(X_new)
print("Prediction: {}".format(prediction))
print("Predicted target name: {}".format(iris_dataset['target_names'][prediction]))
```


# KNN Teórica

### Algoritmo KNN

- Construção do modelo
  - Guardar o conjunto de treino.

- Previsão de um exemplo
  - Encontrar os K exemplos mais próximos no conjunto de treino.
  - Atribuir a etiqueta da maioria.

- Lazy learning.

### Fronteira de Decisão

- É a fronteira que faz a divisão onde o algoritmo atribui uma classe a outra.

- É calculada através da previsão de todos os possíveis exemplos de teste.

### Exatidão como função do número de vizinhos

- Previsão sobre o conjunto de treino
  - 1 vizinho
    - Previsão perfeita.
  - Mais vizinhos
    - O modelo torna-se mais simples e a exatidão decresce.

- Previsão sobre conjunto de teste
  - 1 vizinho
    - Menor quando comparada com modelos que usam mais vizinhos.
    - O modelo é demasiado complexo.
  - 10 vizinhos
    - O modelo é demasiado simples.
  - Melhor desempenho
    - 6 vizinhos.

## Parâmetros e características
### Parâmetros

- **Nº de vizinhos**.

- Peso dos vizinhos
  - Uniforme
  - Inversamente proporcional à distância

- **Função de distância**
  - Minkowski, p
  - Euclideana (p=2)
  - Manhattan (p=1)
  - Máximo (p=infinito)

- Cálculo dos vizinhos mais próximos
  - Força bruta (calcula a distância com todos os pontos).
  - Cáculo otimizado (BallTree, KDTree).

### Função de distância e similaridade

- **Distância e similaridade** - valores numéricos
  - Minkowski, p
  - Euclideana (p=2)
  - Manhattan (p=1)

- **Distância e similaridade** - valores lógicos
  - Simple Matching and Jaccard Coefficients.
  - SMC - number of matches / number of attributes = (f11 + f00) / (f01 + f10 + f11 + f00)
  - J = number of 11 matches / number of non-zero attributes = (f11) / (f01 + f10 + f11)

- **Similaridade do coseno**
  - Cos(d1, d2) = <d1, d2> / (||d1|| ||d2||)

- Outras
  - Correlação
    - Avalia relações lineares.
    - Não avalia dependência estatística em geral.
  - Covariância.
  - Desvio padrão.
  - Informação mútua.

### Características KNN

- Pontos fortes
  - Fácil de perceber.
  - Muitas vezes dá bons resultados sem grandes ajustes.

- Pontos fracos
  - A previsão é lenta (cálculo dos vizinhos).
  - Não tem bom desempenho quando existem muitos atributos.

- Outras considerações
  - É importante fazer o pré-processamento dos dados.
  - É um bom algoritmo baseline.

### Regressão

- Prever um **valor numérico contínuo**.

- Exemplos
  - prever rendimento anual a partir da educação, idade e onde vive.
  - prever a colheita de milho duma plantação, a partir de colheitas anteriores, clima e número de funcionários.

### Modelos lineares

- Combinação linear
  - $w_{1} * x_{1} + ... + w_{n} * x_{n} + b$
  - $x_{1}, ..., x_{n}$ são atributos, $w_{1}, ..., w_{n}, b$ são coeficientes.

- Aprendizagem
  - encontrar pesos w1, ..., wn, b que aproximam o conjunto de dados.

- Modelo
  - hiperplano, soma pesada dos atributos.

- Comparado com KNN parece muito restritivo
  - mas é poderoso para conjuntos com muitos atributos.

- Existe uma grande variedade de modelos lineares

- Diferenciam-se
  - na forma comos os parâmetros são aprendidos.
  - como a complexidade é controlada.
  
- Modelos populares
  - regressão linear.
  - regressão Ridge.
  - Lasso.

### Regressão linear

- É o modelo de regressão mais clássico e simples.

- Aprendizagem
  - Encontra os parâmetros w e b que minimizam o erro quadrático médio entre as previsões e os valores reais de regressão no conj de treino.

- Erro quadrático médio (MSE - Mean Square Error)
  - soma dos quadrados das diferenças entre as previsões e os valores reais.

- Características
  - Não têm parâmetros.
  - Não é possível controlar a complexidade.

- Também conhecido como Ordinary Least Squares (OLS).

### Regressão por k-vizinhos

- **Algoritmo**
  - Contrução do modelo.
  - Guardar o conjunto de treino.

- **Previsão de um exemplo**
  - Encontrar os K exemplos mais próximos no conjunto de Treino.
  - Atribuir a média dos vizinhos.

- **Coeficiente $R^{2}$** (R = coeficiente de correlações de Pearson)
  - coeficiente de determinação.
  - medida estatística que indica quão bem as previsões se aproximam dos dados reais.
  - normalmente um valor entre 0 e 1.

- **1 - corresponde a uma previsão perfeita**
  - o modelo explica completamente a variabilidade dos dados reais.

- **0 - corresponde a um modelo constante que prevê a média do conjunto de treino**
  - o modelo não explica nenuma variabilidade dos dados.

### Influência do nº de vizinhos

- 1 vizinho
  - previsão pouco estável
    - cada ponto do conjunto treino tem influência nas previsões.
    - valores previstos percorrem todos os pontos do conjunto de treino.

- Mais vizinhos
  - previsões mais suaves mas que não se ajustam tanto aos dados de treino.