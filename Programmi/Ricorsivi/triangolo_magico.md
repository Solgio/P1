# Triangolo Magico

## Confronto

```c

int t(int x, int y){
    if(x==0 && y==0){
        return 1;
    }

    if(y<0 || x<0 || y>x){
        return 0;
    }

    return s(x-1, y) + s(x-1, y-1);
}



int s(int x, int y){
    if(x==0 && y==0){
        return 1;
    }

    if( x==0 && y>0){
        return 0;
    }

    if( x>0 && y==0){
    return s(x-1, y);
    }
    return s(x-1, y) + s(x-1, y-1);
}

```

### Equivalenza Estensiva

- Le due funzioni `s()` e `t()` arrivano alla stessa **POST**, seppur _semanticamente diverse_.
  <br><br>

### Equivalenza

- Le due funzioni arrivano alla stessa post ma hanno livelli di **complessità differenti**.
  <br><br>

> [!IMPORTANT]
> L'analisi della complessità induce l'analisi degli elementi
>
>   <br>

### Dimostrazioni di Confronto tra i Programmi

_Proposizione 1:_ hivb,n,<br>
_Proposizione 2:_ L'idea è che la complessità deve essere uguale per entrambi le funzioni.

#### **Dimostrazione 1**

_Proposizione 1:_

#### **Dimostrazione 1**

_Proposizione 1:_

#### **Passo induttivo**

_Proposizione 1:_

**CASO 1**

**CASO 2**

**CASO 3**
