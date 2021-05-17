# distr.py
# math.exp( expoente ) = e^expoente
# math.factorial
# math.pi

import math

PI = math.pi
MAX_DISCRETA = 5
MAX_CONTINUA = 2

# discretas
def uniforme(N):
  return 1 / N

def bernoulli(x, p):
  return (p ** x) * ((1 - p) ** (1 - x))

def binomial(n, p, x):
  combi = (math.factorial(n)) / ((math.factorial(x)) * (math.factorial(n - x)))
  return combi * (p ** x) * ((1 - p) ** (n - x))

def binomial_negativa(x, k, p):
  combi = (math.factorial(x - 1)) / (math.factorial(k - 1)) * (math.factorial((x - 1) - (k - 1)))
  return combi * (p ** k) * ((1 - p) ** (x - k))

def poisson(lamb, x):
  return (math.exp(-lamb) * (lamb ** x)) / math.factorial(x) 

# continuas
def normal(o, u, x):
  lower = 1 / (o * math.sqrt(2 * PI))
  upper = -(1 / 2) * ((x - u) / o) ** 2
  return lower * math.exp(upper)

def exponencial(lamb, x):
  return lamb * math.exp(-lamb * x)
 


if __name__ == '__main__' :
  tipo = None  
  distri = 0

  # se discreta -> uniforme, bernoulli. binomial, binomial negativa, poisson
  # se continua -> normal, exponencial

  while tipo == None:
    tipo = input("tipo de distribuicao (discreta ou continua): ")   
    if tipo == 'discreta':
      while distri == 0:
        distri = int(input("Indique a distribuicao discreta que pretende excutar (1-uniforme, 2-bernoulli, 3-binomial, 4-binomial negativa, 5- poisson): "))
        if distri not in range(1, MAX_DISCRETA + 1):
          distri = 0
          print("Must be in range of 1-5.")
    elif tipo == 'continua':
      while distri == 0:
        distri = int(input("Indique a distribuicao continua que pretende executar (1-normal, 2-exponencial): "))
        if distri not in range(1, MAX_CONTINUA + 1):
          distri = 0
          print("Must be in range of 1-5.") 
    else:
      tipo = None
      print("Try again.")
    
  if tipo == 'discreta':
    if distri == 1:
      N = int(input("N = "))
      print("Resultado:",  uniforme(N))
    elif distri == 2:
      p = float(input("p = "))
      x = int(input("x = "))
      print("Resultado:", bernoulli(x, p))
    elif distri == 3:
      p = float(input("p = "))
      x = int(input("x = "))
      n = int(input("n = "))
      print("Resultado:", binomial(n, p, x))
    elif distri == 4:
      x = int(input("x = "))
      k = int(input("k = "))
      p = float(input("p = "))
      print("Resultado", binomial_negativa(x, k, p))
    else:
      lamb = float(input("lambda = "))
      x = int(input("x = "))
      print("Resultado:", poisson(lamb, x))

  if tipo == 'continua':
    if distri == 1:
      o = float(input("o = "))
      u = float(input("u = "))
      x = int(input("x = "))
      print("Resultado:", normal(o, u, x))
    else:
      lamb = float(input("lambda = "))
      x = int(input("x = "))
      print("Resultado:", exponencial(lamb, x))
