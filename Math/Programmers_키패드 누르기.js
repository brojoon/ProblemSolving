const getDistance = (locatedNumber, target) => {
  const keyPad = {
    1: [0, 0],
    2: [0, 1],
    3: [0, 2],
    4: [1, 0],
    5: [1, 1],
    6: [1, 2],
    7: [2, 0],
    8: [2, 1],
    9: [2, 2],
    "*": [3, 0],
    0: [3, 1],
    "#": [3, 2],
  };

  const curPosition = keyPad[locatedNumber];
  const targetPosition = keyPad[target];

  return (
    Math.abs(targetPosition[0] - curPosition[0]) +
    Math.abs(targetPosition[1] - curPosition[1])
  );
};

function solution(numbers, hand) {
  var answer = [];
  let leftHandPosition = "*";
  let rightHandPosition = "#";

  numbers.forEach((number) => {
    if (number === 1 || number === 4 || number === 7) {
      leftHandPosition = number;
      answer.push("L");
      return;
    }
    if (number === 3 || number === 6 || number === 9) {
      rightHandPosition = number;
      answer.push("R");
      return;
    }

    const leftHandDistance = getDistance(leftHandPosition, number);
    const rightHandDistance = getDistance(rightHandPosition, number);

    if (leftHandDistance === rightHandDistance) {
      if (hand === "left") {
        leftHandPosition = number;
        answer.push("L");
        return;
      }
      if (hand === "right") {
        rightHandPosition = number;
        answer.push("R");
        return;
      }
    }
    if (leftHandDistance > rightHandDistance) {
      rightHandPosition = number;
      answer.push("R");
      return;
    }
    if (rightHandDistance > leftHandDistance) {
      leftHandPosition = number;
      answer.push("L");
      return;
    }
  });
  return answer.join("");
}
