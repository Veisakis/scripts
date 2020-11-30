def is_valid_IP(strng):
    answer = True

    ip_list = strng.split('.')
    size = len(ip_list)

    if size != 4:
        answer = False

    for i in range(size):

        number = ip_list[i]

        if number.isdigit() and int(number) <= 255:

            if (list(number)[0] == '0') and (len(number) != 1):
                answer = False

            pass

        else:
            answer = False

    return answer
