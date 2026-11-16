# Piano Interativo 🎹

Um piano de 12 teclas feito com Arduino, para crianças de 10 e 11 anos montarem e tocarem. Projeto de um grupo da faculdade de Mecatrônica, feito para ser copiado e compartilhado.

## O que tem aqui

- **[Abrir o app](web/)**: o teclado na tela, melodias para aprender e um jogo da memória. Funciona no Google Chrome ou no Microsoft Edge, no computador.
- **[MONTAGEM.md](MONTAGEM.md)**: lista de peças, ligações, como enviar o código e o que fazer se algo der errado.
- **[Codigo_Piano/Codigo_Piano.ino](Codigo_Piano/Codigo_Piano.ino)**: o código do Arduino.
- **[web/COMO_USAR.md](web/COMO_USAR.md)**: como usar e compartilhar o app.

## Como funciona

Cada botão do piano físico toca uma nota no buzzer e avisa o app pelo cabo USB. O app acende a tecla na tela. No jogo da memória, o app manda as notas para o Arduino tocar.
