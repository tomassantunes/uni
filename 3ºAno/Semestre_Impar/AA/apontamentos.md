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