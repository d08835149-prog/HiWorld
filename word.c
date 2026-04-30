#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int words = 0, spaces = 0;
    int i = 0;
    int inWord = 0; // 단어 내부인지 확인하는 플래그

    printf("문장을 입력하세요: ");
    // 공백을 포함하여 한 줄 전체를 입력받음
    fgets(sentence, sizeof(sentence), stdin);

    while (sentence[i] != '\0' && sentence[i] != '\n') {
        if (isspace(sentence[i])) {
            spaces++;
            inWord = 0; // 공백을 만나면 단어 밖으로 나옴
        } else {
            if (inWord == 0) {
                words++;   // 공백이었다가 문자를 만나면 새로운 단어 시작
                inWord = 1;
            }
        }
        i++;
    }

    // 결과 출력
    printf("words: %-10d space: %-10d\n", words, spaces);

    return 0;
}
