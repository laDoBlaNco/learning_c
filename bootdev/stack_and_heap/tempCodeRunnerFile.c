   for (int i = 0; i < sizeof(*ptr); i++) {
        ptr[i] = i*i;
    }
    for (int i = 0; i < sizeof(*ptr); i++) {
        printf("Element %d = %d\n",i,ptr[i]);
    }