# Conversor de Imagem PGM para Arte ASCII em C

Bem-vindo ao Conversor de Imagem PGM para Arte ASCII em C! Este é um projeto simples e divertido que permite transformar imagens no formato PGM em incríveis representações em arte ASCII. Com este programa, você pode criar imagens de arte ASCII personalizadas a partir de suas imagens favoritas e compartilhá-las.

## Como usar  

**Compilação:** Antes de usar o programa, você precisa compilá-lo. Certifique-se de ter um compilador C instalado em seu sistema. No terminal, navegue até a pasta do projeto e execute o seguinte comando de compilação:  
**`gcc ascii_art.c -o ascii_art`**

**Execução:** Agora você está pronto para executar o programa. Use o seguinte comando no terminal:  
**`./ascii_art <nome-imagem[.pgm]> <pixelColuna> <pixelLinha> <caracteres>`**  

- `<nome-imagem[.pgm]>`: O nome da imagem no formato PGM que você deseja converter.  
- `<pixelColna>`: O número de colunas desejado para a resolução da arte ASCII.  
- `<pixelLinha>`: O número de linhas desejado para a resolução da arte ASCII.  
- `<caracteres>`: Uma lista de caracteres que você deseja usar para criar a representação ASCII. Quanto mais caracteres você fornecer, mais detalhada será a arte.

Exemplo:
`./ascii_art image.pgm 150 100 "#$@!*:,. "`

**Resultado:** Após a execução bem-sucedida, um arquivo chamado result.txt será gerado na pasta do projeto. Este arquivo conterá a arte ASCII resultante, usando os caracteres e resolução que você especificou.  

**Contribuição**  
Este é um projeto de código aberto, e encorajamos contribuições da comunidade. Se você tiver alguma melhoria, correção de bugs ou recursos adicionais que gostaria de adicionar, fique à vontade para enviar um pull request.  
