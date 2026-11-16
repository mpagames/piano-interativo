# Piano Interativo: versão web

O app inteiro está em um único arquivo: `index.html`. Não precisa instalar Python nem nenhum programa.

## Como usar

1. Ligue o piano físico no computador pelo cabo USB.
2. Abra o `index.html` no **Google Chrome** ou no **Microsoft Edge**, no computador.
   (Firefox, Safari e celular não conseguem conversar com o Arduino.)
3. Clique em **🔌 Conectar piano**, no canto de baixo do menu, escolha a porta do Arduino na lista e clique em **Conectar**.
4. Pronto: quando o status ficar verde ("Piano conectado ✓"), os botões do piano físico acendem as teclas na tela.

Da segunda vez em diante, o navegador lembra o piano e conecta sozinho, inclusive se o cabo for tirado e ligado de novo.

**Se não conectar:** feche a IDE do Arduino (o Monitor Serial dela "prende" a porta) e tente de novo.

**Sem o piano físico** dá para testar clicando nas teclas da tela ou usando o teclado do computador:

| Tecla do computador | A | W | S | E | D | F | T | G | Y | H | U | J |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Nota | Dó | Dó♯ | Ré | Ré♯ | Mi | Fá | Fá♯ | Sol | Sol♯ | Lá | Lá♯ | Si |

## Como o app conversa com o Arduino

- **Arduino → app:** quando um botão é apertado, o Arduino envia uma linha com um número de 1 a 12 (`Serial.println(numero)`, a 9600 baud):
  1 = Dó, 2 = Dó♯, 3 = Ré, 4 = Ré♯, 5 = Mi, 6 = Fá, 7 = Fá♯, 8 = Sol, 9 = Sol♯, 10 = Lá, 11 = Lá♯, 12 = Si.
- **App → Arduino:** no jogo da memória, quando o app mostra a sequência, ele também envia o número de cada nota para o Arduino (no mesmo formato), e o Arduino toca a nota no buzzer.

A montagem do piano físico está em `../MONTAGEM.md`.

## Como compartilhar

Escolham uma destas opções:

- **Enviar o arquivo:** mandem o `index.html` por e-mail, Drive ou WhatsApp. Quem receber abre com dois cliques no Chrome ou no Edge.
- **Um link (GitHub Pages, grátis):** criem um repositório no GitHub, enviem o `index.html` e ativem em *Settings → Pages*. O link fica como `https://seu-usuario.github.io/nome-do-repositorio/`. Quando vocês atualizarem o arquivo, todo mundo recebe a versão nova.
- **Um link sem criar repositório:** arrastem a pasta `web` para o [Netlify Drop](https://app.netlify.com/drop).

## Como adicionar uma música

No `index.html`, procurem `const MUSICAS` e adicionem uma entrada com o nome e as notas. Depois, em `const CARTOES`, coloquem a chave da música no cartão (no lugar de `chave: null`).
