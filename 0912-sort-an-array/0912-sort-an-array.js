/**
 * @param {number[]} nums
 * @return {number[]}
 */

var sortArray = function(arr) {
    let s = 0;
    let e = arr.length -1
    mergeSort(arr,s,e);
    return arr
};
function mergeSort(arr,s,e){
    var mid=Math.floor((s+e)/2)
    if(s>=e)return;
    mergeSort(arr,s,mid)
    mergeSort(arr,mid+1,e)
    merge(arr,s,e)
}
function merge(arr, s, e) {
    var mid = Math.floor((e - s) / 2) + s;
    let first = []
    let second = []

    let k = s;
    for (let i = 0; i <= mid - s; i++) {
        first[i] = arr[k++]
    }
    k = mid + 1;
    for (let i = 0; i < e - mid; i++) {
        second[i] = arr[k++]
    }

    let index1 = 0
    let index2 = 0
    k = s
    while (index1 < first.length && index2 < second.length) {
        if (first[index1] < second[index2]) {
            arr[k++] = first[index1++]
        } else {
            arr[k++] = second[index2++]
        }
    }
    while (index1 < first.length) {
        arr[k++] = first[index1++]
    }
    while (index2 < second.length) {
        arr[k++] = second[index2++]
    }
}
