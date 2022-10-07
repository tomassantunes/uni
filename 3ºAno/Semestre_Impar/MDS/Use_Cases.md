# Use Cases - Lan Party

## Atores
- Humanos
  1. Jogador
  2. Espectador
  3. Administrador

- Não humanos
  1. Forma de Pagamento
     1. MBWay
     2. PayPal
     3. PaySafeCard
     4. Multibanco
  2. API

## Use Cases do sistema
  1. Criar uma conta para aceder à plataforma do torneio.
  2. Autenticação na plataforma.
  3. Inscrição nos diversos torneios.
  4. Realização de pagamentos.
  5. Participação nos jogos.
  6. Consulta de resultados.
  7. Criar um utilizador.
  8. Apagar um utilizador.
  9. Modificar as tabelas de resultados.

## Ações comuns entre Use Cases
  1. Autenticação na plataforma (3, 4, 5).
  2. Ter permissões de Administrador (7, 8, 9).

## Comportamentos
  1. Criar conta de utilizador.
  - Ator principal: Jogador.
  - Comportamento normal:
    1. Introduzir um nickname único.
    2. Introduzir um endereço de email válido.
    3. Escolher uma password.
    4. Re-introdução da password.
    5. Escolha de categoria (Estudante, Participante Externo, Espectador).
    6. Aguardar pelo mail de Validação da conta.
    7. Introdução do código de validação da conta.
  - Comportamento alternativo:
    1. Introduzir um nickname único:
       1. O nickname já existe. Avisa o utilizador e volta ao ínicio.
    2. Introduzir um endereço de email válido.
       1. O email já existe. Avisa o utilizador e volta ao ponto 2.
       2. O email é inválido. Avisa o utilizador e volta ao ponto 2.
    3. Escolher uma password.
       1. A password é muito curta. Avisa o utilizador e volta ao ponto 3.
       2. O campo está vazio. Avisa o utilizador e volta ao ponto 3.
    4. Re-introdução da password.
       1. A password não corresponde com a escolhida anteriormente. Avisa o utilizador e volta ao ponto 4.
    7. Introdução do código de validação da conta.
       1. O código está errado. Avisa o utilizador e volta ao ponto 7.
       2. O código expirou. Avisa o utilizador e volta ao ponto 6.
       3. O código não foi enviado. Avisa o utilizador e volta ao ponto 6.