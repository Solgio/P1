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
