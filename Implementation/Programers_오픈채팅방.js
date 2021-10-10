function solution(record) {
	let arr = [];
	var answer = [];
	for (int i = 0; i < record.size(); i++)
			arr.push(record.split(" "));
	set = new Set();
	for (int i = record.size() - 1; i >= 0; i--)
	{
			if (!(set.has(arr[i][1])))
			{
					if (arr[i][0] != "Leave")
					{   
							set.add(arr[i][1]);
							map.set(arr[i][1], arr[i][2]);
					}
			}
	}
	for (int i = 0; i < record.size(); i++)
	{
			let result = "";
			if (arr[i][0] == "Enter")
			 {
					result += map.get(arr[i][1]);
					result += "님이 들어왔습니다.";
					answer.push(result);
			 }   
			else if(arr[i][0] == "Leave")
			{
					result += map.get(arr[i][1]);
					result += "님이 나갔습니다.";
					answer.push(result);
			}
	}
	
	return answer;
}