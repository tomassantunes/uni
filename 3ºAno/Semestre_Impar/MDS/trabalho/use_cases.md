## Atores

### Humanos
- Cliente.
- Estafeta.
- Administrador.

### Não Humanos
- Restaurante
- Formas de Pagamento
  - MB Way.
  - Cartão de Crédito.

## Use Cases do Sistema
1. Criar uma conta de cliente.
2. Realizar inscrição como estafeta.
3. Realizar inscrição como restaurante.
4. Aprovar inscrições.
5. Realizar uma compra.
6. Customizar ofertas (por parte do restaurante).
7. Aceder às encomendas (por parte do restaurante).
8. Aceder às encomendas (por parte do estafeta).
9. Aceder às encomendas efetuadas (por parte do cliente).
10. Cancelar uma encomenda (por parte do cliente).
11. Cancelar uma entrega (por parte do estafeta).
12. Escolher encomenda a entregar (estafeta).

## Ações comuns entre Use Cases


## Comportamentos
### Comportamentos Use Case 1:
- Criar uma conta de cliente.
  - Ator principal: Cliente.
  - Comportamento normal:
    1. Introduzir o nome e apelido.
    2. Introduzir um endereço de email válido.
    3. Escolher uma password.
    4. Re-introdução da password.
  - Comportamento alternativo:
    - 2.1 O email é inválido ou já existe.
    - 2.2 Introdução de um novo email.
    - 3.1 A password é muito curta.
    - 3.2 Introdução de uma password nova. 
    - 4.1 As passwords não correspondem.
    - 4.2 Re-introdução da password escolhida no ponto 3.

### Comportamentos Use Case 2:
- Realizar inscrição como estafeta.
  - Ator principal: Estafeta.
  - Comportamento normal:
    1. Introduzir o nome e apelido.
    2. Introduzir um endereço de email válido.
    3. Escolher uma password.
    4. Re-introdução da password.
    5. Apresentar BI/Cartão de Cidadão.
    6. Especificar o tipo de veículo a ser usado.
    7. Caso seja um veículo que necessite de carta, apresentar a mesma.
  - Comportamento alternativo:
    - 2.1 O email é inválido ou já existe.
    - 2.2 Introdução de um novo email.
    - 3.1 A password é muito curta.
    - 3.2 Introdução de uma password nova. 
    - 4.1 As passwords não correspondem.
    - 4.2 Re-introdução da password escolhida no ponto 3.
    - 5.1 O documento não é válido.
    - 5.2 Submissão de um documento válido.
    - 7.1 O documento não é válido.
    - 7.2 Submissão de um documento válido.

### Comportamentos Use Case 3:
- Realizar a inscrição como restaurante.
  - Ator principal: Restaurante.
  - Comportamento normal:
    1. Introduzir nome do establecimento.
    2. Introduzir endereço de email válido.
    3. Introduzir uma password.
    4. Re-introdução da password.
    5. Introdução da Morada
    6. Introudção de NIF do restaurante.
    7. Escolha do tipo de comida.
  - Comportamento alternativo:
    - 2.1 O email é inválido ou já existe.
    - 2.2 Introdução de um novo email.
    - 3.1 A password é muito curta.
    - 3.2 Introdução de uma password nova. 
    - 4.1 As passwords não correspondem.
    - 4.2 Re-introdução da password escolhida no ponto 3.
    - 5.1 A morada não é válida.
    - 5.2 Introdução de uma morada válida.
    - 6.1 NIF inválido.
    - 6.2 Introdução de um NIF válido.

### Comportamentos Use Case 4
- Aprovar inscrições.
  - Ator principal: Administrador.
  - Comportamento normal:
    1. Seleção da inscrição a aprovar.
    2. Análise da inscrição.
    3. Aprovação/Negação da inscrição em questão.

### Comportamentos Use Case 5
- Realizar uma compra.
  - Ator principal: Cliente.
  - Comportamento normal:
    1. O cliente seleciona o restaurante de que quer encomendar.
    2. O cliente adiciona a comida que pretende encomendar ao carrinho.
    3. Definir uma morada vá- lida de entrega.
    4. O cliente efetua o pagamento.
    5. O cliente recebe a encomenda na morada definida.
  - Comportamento alternativo:
    - 3.1 A morada não é válida.
    - 3.2 Introduzir uma morada válida.
    - 4.1 A forma de pagamento é inválida.
    - 4.2 Introduzir uma nova forma de pagamento.

### Comportamentos Use Case 6
- Costumizar ofertas.
  - Ator principal: Restaurante.
  - Comportamento normal:
    1. O restaurante acede às suas ofertas.
    2. O restaurante costumiza as suas ofertas.
    3. O restaurante adiciona promoções (se for o caso).
    4. O restaurante confirma as alterações.

### Comportamentos Use Case 7
- Aceder às encomendas.
  - Ator principal: Restaurante.
  - Comportamento normal:
    1. O restaurante acede à lista de encomendas.
  - Comportamento alternativo:
    - 1.1 Não existem encomendas ativas. 

### Comportamentos Use Case 8
- Aceder às encomendas.
  - Ator principal: Estafeta.
  - Comportamento normal:
    1. O estafeta acede à lista de encomendas.
  - Comportamento alternativo:
    - 1.1 Não existem encomendas ativas.

### Comportamentos Use Case 9
- Aceder às encomendas efetuadas.
  - Ator principal: Cliente.
  - Comportamento normal:
    1. O cliente acede à lista das suas encomendas.
  - Comportamento alternativo:
    - 1.1 Não existem encomendas efetuadas pelo cliente.