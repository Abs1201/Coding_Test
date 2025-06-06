def merge_dna_sequences(seq1: str, seq2: str, overlap_len: int = 100):
    """
    seq1의 뒤쪽과 seq2의 앞쪽에서 최대 overlap을 찾아 겹치는 부분 병기 후 병합

    :param seq1: 첫 번째 DNA 서열
    :param seq2: 두 번째 DNA 서열
    :param overlap_len: 비교할 최대 overlap 길이
    :return: 병합된 DNA 서열
    """

    def format_base(a, b):
        """염기가 다를 경우 병기, 같으면 하나만 출력"""
        return a if a == b else f"{a}/{b}"

    max_overlap = 0
    best_merge = ""

    # overlap 길이를 길이 높은 것부터 시도
    for i in range(overlap_len, 10, -1):
        tail = seq1[-i:]
        head = seq2[:i]

        # 유사도 계산 (일치한 염기 수)
        matches = sum(1 for a, b in zip(tail, head) if a == b)
        similarity = matches / i

        if similarity >= 0.85:  # 기준 유사도
            # 병기된 부분 생성
            merged_overlap = ''.join(format_base(a, b) for a, b in zip(tail, head))
            best_merge = seq1[:-i] + merged_overlap + seq2[i:]
            max_overlap = i
            break

    if max_overlap == 0:
        print("충분히 겹치는 구간이 없습니다. 그냥 붙였습니다.")
        return seq1 + seq2

    return best_merge


# 예시 사용
seq1 = "CCTGTGTTGAGAATGAGTTTGTTGCCTTGAAGAAGGACGTGGACACAGCCTTCCTGATGAAGGCTGACCTGGAGACCAACGCAGAGGCACTCGTGCAGGAGATCGACTTCCTGAAAAGCCTGTATGAGGAGGAGATCTGCCTGCTCCAGTCTCAGATCTCTGAGACCTCGGTCATTTTGAACATGGACAACAGCCGGGAGCACCGGATGTCCTCTGCGC"  # 첫 번째 시퀀스 전체
seq2 = "TCTCTGCCTCGGAAGTGAGTGCTTCTGCCATCGTCCCCTGCCTGTTCGTGCTGGAGATCGACGTCCTGAAAAGCCTGTATGTGGAGGAGATCTGCCTGCTCCAGTCTCAGATCTCTGAGACCTCGGTCATTGTGAAGATGGACAACAGCCGGGAGCTGGACGTGGACGGCATCATCGCTGAGATCAAGGCGCAGTATGACGACATCGCCAGCCGCAGCAAAGCCGAAGCAGAGGCCTGGTACCAGTGCCGGTATGAGGAGCTGAGAGTCACAGCTGGGAACCACTGTGA"  # 두 번째 시퀀스 전체

# 일단 본문에서는 seq1, seq2 생략됨. 실제 값을 넣어주세요.
result = merge_dna_sequences(seq1, seq2, overlap_len=100)
print(result)
