#[allow(dead_code)]
static PATH_OUTPUT: &str = "src/Graph/graph_test";
#[allow(dead_code)]
static PATH_SOURCE: &str = "src/Graph/graph_test.cpp";

#[cfg(test)]
mod compile {
    use super::*;
    use crate::compile_cpp;

    #[test]
    fn graph_compile_test() {
        let commend = compile_cpp::genrate_cli_compile(
            compile_cpp::Complier::GPlusPlus,
            PATH_SOURCE,
            PATH_OUTPUT,
        );

        let output = compile_cpp::run_commend(&commend);
        assert!(
            output.status.success(),
            "Compiler_Error: {:#?}",
            String::from_utf8(output.stderr)
        );
    }
}

#[cfg(test)]
mod searching {
    use super::*;
    use crate::compile_cpp;
    use rand::Rng;

    #[test]
    fn graph_bfs() {
        for _ in 0..10 {
            run_search_test("--bfs");
        }
    }

    #[test]
    fn graph_dfs() {
        for _ in 0..10 {
            run_search_test("--dfs");
        }
    }

    #[test]
    fn graph_a_star() {
        for _ in 0..10 {
            run_search_test("--A*");
        }
    }

    fn run_search_test(flag: &str) {
        let file_type = compile_cpp::get_output_file(PATH_OUTPUT);
        let mut nodes: Vec<&str> = vec!["A", "B", "C", "D", "E", "F", "G", "K", "L"];

        let mut rng = rand::thread_rng();

        let index: usize = rng.gen_range(0..nodes.len());
        let input_start = nodes[index].clone();

        nodes.remove(index);
        let input_end = nodes[rng.gen_range(0..nodes.len())];

        let mut str_inputs = format!("{} {} ", input_start, input_end);

        str_inputs.push_str(flag);
        let commend = format!("{} {}", file_type, str_inputs);

        println!("{commend}");
        let output = compile_cpp::run_commend(&commend);
        let mut str_output = String::new();

        assert!(
            output.status.success(),
            "Run_Time_Error: {:#?}",
            String::from_utf8(output.stderr)
        );
        str_output.push_str(&format!("{:#?}", String::from_utf8(output.stdout)));

        let mut paths: Vec<String> = Vec::new();

        let mut word = String::new();
        let mut is_char = false;
        str_output = str_output.replace("Ok", "");
        for c in str_output.chars() {
            if c.is_alphabetic() {
                word.push(c);
                is_char = true;
            }
            if c == ' ' && is_char {
                is_char = false;
                paths.push(word.clone());
                word.clear();
            }
        }
        assert_eq!(input_start, paths[0]);
        assert_eq!(input_end, paths.last().unwrap());
    }
}
/*
 *		 (A) ====== (C) ====== (E) \
 *		  |          |          |   \
 *		  |          |          |    \
 *		 (L) ====== (K) ============ (G)
 *	    |	         |          |    /
 *	    |          |          |   /
 *		 (B) ====== (D) ====== (F) /
 */
