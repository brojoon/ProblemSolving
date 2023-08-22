function solution(storey) {
    let count = 0;
    while(storey > 0) {
        const mod = storey % 10;
        storey = Math.floor(storey / 10);

        if(mod === 5) {
            count += 5;
            if(storey % 10 >= 5) storey++;
        } else if(mod < 5) {
            count += mod;
        } else if(mod > 5) {
            count += (10 - mod);
            storey++;
        }
    }

    return count;
}