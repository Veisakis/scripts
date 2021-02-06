def to_jaden_case(string):
    phrase_words = string.split()
    jaden_phrase = []

    for word in phrase_words:

        ls_word = list(word)

        first = ls_word[0].upper()
        rest = ls_word[1:]

        rest.insert(0, first)
        jaden_word = "".join(rest)

        jaden_phrase.append(jaden_word)

    jaden_case = ' '.join(jaden_phrase)
    print(jaden_case)
    return jaden_case


phrase = input('Give a phrase: ')
to_jaden_case(phrase)
