function solution(name, yearning, photo) {
    return photo.map((p) => p.reduce((a, c) => a += yearning[name.indexOf(c)] ?? 0, 0));
}