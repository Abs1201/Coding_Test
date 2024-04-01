

function LCS(X, Y) { // Longest Common Subsequence

    let m = X.length;
    let n = Y.length;
    let dp = Array.from(Array(m + 1), () => Array(n + 1).fill(0));


    // Build the LCS table
    for (let i = 0; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            if (i === 0 || j === 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] === Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the LCS
    let lcs = [];
    let i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] === Y[j - 1]) {
            lcs.unshift(X[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}

function hasNextAfterOption(text, option){
    let optionNextIndex = text.indexOf(option)+option.length;
    if(option[optionNextIndex]!=' '){
        return true;
    }
    return false;
    
}

function splitWithOption(text, option) {
    let optionIndex = text.indexOf(option);
    if (optionIndex === -1) return text.split(' ');

    let beforeOption = text.substring(0, optionIndex).trim();
    let afterOption = text.substring(optionIndex + option.length).trim();

    let words = beforeOption.split(' ');
    if (beforeOption.length > 0) words.push(option);
    return words.concat(afterOption.split(' '));
}

function findDifferences(bonText, chgText, optiontxt) {
    let bonWords = bonText.split(' ');
    let chgWords = null;

    if (!(optiontxt == null || optiontxt == undefined || optiontxt.length == "")) {
        chgWords = chgText.includes(optiontxt) ? splitWithOption(chgText, optiontxt) : chgText.split(' ');
    } else {
        chgWords = chgText.split(' ');
    }

    // Find the LCS
    let lcs = LCS(bonWords, chgWords);
    
    let chgOptionIndex = chgWords.indexOf(optiontxt);
    
    let hasNext = hasNextAfterOption(chgText,optiontxt);
    let chgBIndex=chgOptionIndex;
    for(;chgBIndex>=0; chgBIndex--){
        if(lcs.includes(chgWords[chgBIndex])){
            break;
        }
    }
    let chgWordBeforeOption = chgBIndex==-1 ? "":chgWords[chgBIndex];
    let bonBeforeWordIndex = chgBIndex==-1 ? -1:bonWords.indexOf(chgWordBeforeOption);
    
    let chgAIndex=hasNext?chgOptionIndex:chgOptionIndex+1;
    for(;chgAIndex<chgWords.length; chgAIndex++){
        if(lcs.includes(chgWords[chgAIndex])){
            break;
        }
    }
    let chgWordAfterOption = chgAIndex==chgWords.length ? "":chgWords[chgAIndex];
    let bonAfterWordIndex = chgAIndex==chgWords.length ? -1:bonWords.indexOf(chgWordAfterOption);
    bonWords=bonWords.slice(++bonBeforeWordIndex, bonAfterWordIndex);
    chgWords=chgWords.splice(chgOptionIndex, hasNext?2:1);
    console.log("bonWords:");
    console.log(bonWords, "\n");
    console.log("chgWords:");
    console.log(chgWords, "\n");
    console.log("lcs: ");
    console.log(lcs);
    
    let tmp = chgWords.at(-1).length;
    bonWords[bonWords.length-1] = bonWords.at(-1).slice(0,bonWords.at(-1).length-1);
    
    return bonWords;
    
    // let diffArr = [], diffArr2 = [];

    // // Initialize indexes for both texts
    // let bonIndex = 0, chgIndex = 0;

    // // Initialize positions for both texts
    // let bonPos = 0, chgPos = 0;

    // while (bonIndex < bonWords.length) {
    //     let bonWord = bonWords[bonIndex] || "";

    //     if (!lcs.includes(bonWord)) {
    //         // If the word doesn't exist in the LCS, it's a difference
    //         diffArr.push({
    //             bonText: bonWord,
    //             bonStartPos: bonPos,
    //             bonEndPos: bonPos + bonWord.length,
    //         });
    //     }

    //     // Update positions and indexes
    //     bonPos += bonWord.length + (bonWord.length > 0 ? 1 : 0);
    //     bonIndex += bonWord.length > 0 ? 1 : 0;
    // }

    // while (chgIndex < chgWords.length) {
    //     let chgWord = chgWords[chgIndex] || "";

    //     if (!lcs.includes(chgWord)) {
    //         // If the word doesn't exist in the LCS, it's a difference
    //         diffArr2.push({
    //             chgText: chgWord,
    //             chgStartPos: chgPos,
    //             chgEndPos: chgPos + chgWord.length
    //         });
    //     }

    //     // Update positions and indexes
    //     chgPos += chgWord.length + (chgWord.length > 0 ? 1 : 0);
    //     chgIndex += chgWord.length > 0 ? 1 : 0;
    // }

    // //need condition!
    
    // var chgTargetPos;
    // for (let i = 0; i < diffArr2.length; i++) {
    //     if (diffArr2[i]['chgText'] == optiontxt) chgTargetPos = i;
    // }
    // console.log(chgTargetPos);

    // var gSum = chgTargetPos > 0 ? 1 : 0;
    // for (let i = 0; i < chgTargetPos; i++) {
    //     gSum += diffArr2[i]['chgEndPos'] - diffArr2[i]['chgStartPos'];
    // }



    // console.log(diffArr2);



    // return diffArr;
}

const bonText = "제1조(목적) bb 이 a 법은 자본시장에서의 aa 금융혁신과 공정한 경쟁을 촉진하고 실행한다.";
const chgText = "제1조(목적) 이 법은 ㅠㅠ 자본시장에서의 aaa 금융혁신과 공정하지 아니한 완벽한 경쟁을 촉진하고 실행한다.";
var optiontxt = "공정하지 아니한 완벽한 경쟁";

// const bonText = "제2조(당선 통지 및 등록) ① 중앙선거관리위원회 위원장은 국회의원 당선인이 결정된 때에는 그 명단을 즉시 국회에 통지하여야 한다.";
// const chgText = "제2조(당선 통지 및 등록) ① 중앙선거관리위원회 위원장은 대통령 당선인이 결정된 때에는 그 명단을 즉시 국회에 통지하여야 한다.";
// var optiontxt = "대통령 당선인";

const lcsObj = findDifferences(bonText, chgText, optiontxt);

console.log(lcsObj);
for(let i=0; i<lcsObj.length; i++){
     process.stdout.write(lcsObj[i]);
     if(i<lcsObj.length-1){
         process.stdout.write(" ");
     }
     
}

//console.log(lcsObj[0]['chgText']);

// var ans="";

// for(let i=0; i<lcsObj.length; i++){
//     var bt=lcsObj[i]['bonText'], ct=lcsObj[i]['chgText'];
//     if(ct==optiontxt){
//         ans+=bt;
//     }
//     else{
//         var bgap=lcsObj[i]['bonEndPos']-lcsObj[i]['bonStartPos'], cgap=lcsObj[i]['chgEndPos']-lcsObj[i]['chgStartPos'];
//         var bcgap=bgap-cgap;
//         ans+=bt.substring(bcgap,0);
//     }
// }
// console.log(ans);