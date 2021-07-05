
    char pin[7];
    int k=0;
    cout<<"Enter  password : ";
    while(pin[k-1]!='\r') {
        pin[k]=getch();
        if(pin[k-1]!='\r') {
            cout<<"*";
        }
        k++;
    }
    pin[k-1]='\0';
    if(strcmp(pin,pass)==0)
    {
        cout<<"login successfull";
    }
    else
    cout<<"else";
    getch();
