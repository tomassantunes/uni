# Resolução da 2ª frequência de 2018

### 1.

As atividades que fazem parte desta tarefa são:
    
- Gestão de alterações que consiste em manter o "rasto" das alterações feitas, quais os custos destas alterações e decidir quais as alterações que devem ser implementadas.

- Gestão de versões que consiste em manter-se o rasto dos componentes de sistema por forma a garantir que as alterações dos diferentes programadores não interferem umas com as outras.

- Criação do sistema que consiste no processo do commit ir componentes do sistema, dados e bibliotecas, para depois ser possível compilar tudo num sistema executável.

- Gestão de releases que consiste em preparar software para ser entregue e manter registo das versões já entregues.

Sem uma gestão de versões seria impossível manter registo das versões de componentes desenvolvidos, o que dificultaria em grande medida a criação de sistemas.

Sem uma gestão de releases seria impossível manter rasto de diferentes versões (com alterações geridas pela gestão de alteração) dificultando assim a entrega do produto ao cliente.

Todas as atividades estão relacionadas entre si de forma a que seja possível uma boa gestão de configurações, sendo que cada uma depende das outras.

### 2.

A gestão de configurações está preocupada com as políticas, os processos e as ferramentas para gerir um software com alterações constantes.

Esta características são importantes pois é fácil perder o rasto a quais modificações e versões de componentes foram incorporados em cada versão do sistema.

Sem este tipo de gestão seria difícil lançar novas versões onde haveria implementação de novas propostas, correção de falhas e adaptações para diferentes sistemas operativos. Sem uma gestão de configuração efetiva existe a possibilidade de que se perca tempo a modificar uma versão errada do sistema. No mesmo contexto, haverá a possibilidade de ser esquecido o local onde a versão que se pretende modificar está guardada.

A gestão de configurações é assim importante para que o sistema em manuntenção possa evoluir, no sentido em que, serão lançadas novas versões nas quais se corrigiram erros e foram implementadas novas funcionalidades.

### 3.

Quando uma nova versão é criada, o sistema guarda um delta com a lista das diferenças entre a nova versão e a versão mais antiga que foi usada para desenvolver a nova versão.
Deste modo ao aplicar os deltas à versão master (normalmente a mais recente), a versão em questão pode ser recriada.
Através deste método é assim possível optimizar o espaço usado em disco pois não é necessário guardar o código fonte na sua totalidade, sendo apenas necessário guardar as
diferenças entre as diferentes versões.

### 4.

A abordagem correta pode ser: 

1. Demonstrar ao programador e ao cliente que software vai ao encontro dos requisitos. Para software customizado isto quer dizer que deverá haver pelo menos um teste para cada requisito no documento dos requisitos. Para software genérico isto quer dizer que deverá haver testes para cada funcionalidade que será incluída no lançamento da versão. Também se poderá testar as interações entre funcionalidades para ver se há interações indesejadas.

2. Encontrar inputs ou sequências de inputs onde o comportamento do software é incorreto, indesejado ou não está conforme os requisitos. Isto é causado por defeitos (bugs) no software, se faz testes ao software para encontrar defeitos, é com o objetivo de retirar comportamento indesejados como por exemplo, crashs de sistema, interações com outros sistemas, computação incorreta e corrupção de dados.

Na primeira abordagem o objetivo é verificar que o sistema funciona da forma correta, usando uma lista de testes que refletem o uso normal do sistema. Na segunda abordagem o objetivo é testar usando casos desenhados para expor defeitos.

### 5.

A metodologia de desenvolvimento de software baseada em Test Driven Development (TDD) tem como base a intercalação de testes com o desenvolvimento de código e a implementação de testes antes da implementação de código. Desta forma, todos os segmentos de código estão associados pelo menos a um teste, o debug é simplificado (quando um teste falha torna-se óbvio qual o problema), e os testes servem de documentação ao sistema.

### 6.

Os procedimentos de gestão de branches que devem ser seguidos pelos membros da equipa de desenvolvimento para minimizar os conflitos entre diferentes versões de código, são: sempre que se pretende alterar o código fonte do branch master/main deve ser criado um novo branch sendo que este só vai fazer merge com o branch principal quando todos os testes forem bem sucedidos e a equipa aprovar o mesmo.

### 7.

```
git clone git@remote-server/nice-project.git
git add remote origin git@remote-serverawsome-project.git
git add .
git commit -a -m "implementado"
git push origin master 
```

### 8.
