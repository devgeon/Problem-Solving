// BOJ-07604 / Reconstruction Trees
// devgeon, 2025.03.12, Java 11
// https://www.acmicpc.net/problem/7604

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;

    private static int indexOf(final String string, final int ch, final int beginIndex, final int endIndex) {
        for (int i = beginIndex; i < endIndex; i++) {
            if (string.charAt(i) == ch) {
                return i;
            }
        }
        return -1;
    }

    private static void reconstruct(final List<List<Integer>> adjList, final String preorder, final String inorder) {
        int length = preorder.length();
        _reconstruct(adjList, preorder, inorder, 0, length, 0, length);
    }

    private static char _reconstruct(final List<List<Integer>> adjList, final String preorder, final String inorder,
            int preOrdStart, int preOrdEnd, int inOrdStart, int inOrdEnd) {
        char root = preorder.charAt(preOrdStart);
        int inOrdIdx = indexOf(inorder, root, inOrdStart, inOrdEnd);
        // int inOrdIdx = inorder.indexOf(root, inOrdStart, inOrdEnd); // Java 21
        if (inOrdIdx < 0) {
            throw new IndexOutOfBoundsException("Invalid tree");
        }

        int leftChildCount = inOrdIdx - inOrdStart;
        if (leftChildCount > 0) {
            char leftChild = _reconstruct(adjList, preorder, inorder, preOrdStart + 1, preOrdStart + leftChildCount + 1,
                    inOrdStart, inOrdIdx);
            adjList.get(root - 'A').add(leftChild - 'A');
        }

        int rightChildCount = inOrdEnd - inOrdIdx - 1;
        if (rightChildCount > 0) {
            char rightChild = _reconstruct(adjList, preorder, inorder, preOrdStart + leftChildCount + 1, preOrdEnd,
                    inOrdIdx + 1, inOrdEnd);
            adjList.get(root - 'A').add(rightChild - 'A');
        }

        return root;
    }

    private static void printPostorder(List<List<Integer>> adjList, int currNode) throws IOException {
        for (int nextNode : adjList.get(currNode)) {
            printPostorder(adjList, nextNode);
        }
        bw.write(currNode + 'A');
    }

    private static boolean solve() throws IOException {
        String line = br.readLine();
        if (line.equals("#")) {
            return false;
        }

        StringTokenizer st = new StringTokenizer(line);
        String preorder = st.nextToken();
        String inorder = st.nextToken();

        List<List<Integer>> adjList = new ArrayList<>(26);
        for (int i = 0; i < 26; i++) {
            adjList.add(new ArrayList<>());
        }

        try {
            reconstruct(adjList, preorder, inorder);
            printPostorder(adjList, preorder.charAt(0) - 'A');
        } catch (IndexOutOfBoundsException e) {
            bw.write(e.getMessage());
        }
        bw.newLine();

        return true;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (solve()) {
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
