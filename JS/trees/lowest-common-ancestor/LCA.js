class Node {
    constructor(data) {
        this.key = data;
        this.left = null;
        this.right = null;
    }
}

function findLCA(node, n1, n2) {
    if (!node) {
        return null;
    }

    if (node.key === n1 || node.key === n2) {
        return node;
    }

    const leftLCA = findLCA(node.left, n1, n2);
    const rightLCA = findLCA(node.right, n1, n2);

    if (leftLCA !== null && rightLCA !== null) {
        return node;
    }

    return leftLCA !== null ? leftLCA : rightLCA;
}

root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

console.log(findLCA(root, 4, 5).key);