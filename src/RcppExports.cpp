// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// bvs
arma::mat bvs(arma::mat y, arma::mat z, arma::mat a, arma::mat lambda, arma::mat sigma_i, arma::vec prob_prior, Rcpp::Nullable<Rcpp::IntegerVector> include);
RcppExport SEXP _bvartools_bvs(SEXP ySEXP, SEXP zSEXP, SEXP aSEXP, SEXP lambdaSEXP, SEXP sigma_iSEXP, SEXP prob_priorSEXP, SEXP includeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type z(zSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type a(aSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type lambda(lambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma_i(sigma_iSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type prob_prior(prob_priorSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type include(includeSEXP);
    rcpp_result_gen = Rcpp::wrap(bvs(y, z, a, lambda, sigma_i, prob_prior, include));
    return rcpp_result_gen;
END_RCPP
}
// ir
arma::vec ir(Rcpp::List A, int h, std::string type, int impulse, int response);
RcppExport SEXP _bvartools_ir(SEXP ASEXP, SEXP hSEXP, SEXP typeSEXP, SEXP impulseSEXP, SEXP responseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type A(ASEXP);
    Rcpp::traits::input_parameter< int >::type h(hSEXP);
    Rcpp::traits::input_parameter< std::string >::type type(typeSEXP);
    Rcpp::traits::input_parameter< int >::type impulse(impulseSEXP);
    Rcpp::traits::input_parameter< int >::type response(responseSEXP);
    rcpp_result_gen = Rcpp::wrap(ir(A, h, type, impulse, response));
    return rcpp_result_gen;
END_RCPP
}
// kalman_dk
arma::mat kalman_dk(arma::mat y, arma::mat z, arma::mat sigma_u, arma::mat sigma_v, arma::mat B, arma::vec a_init, arma::mat P_init);
RcppExport SEXP _bvartools_kalman_dk(SEXP ySEXP, SEXP zSEXP, SEXP sigma_uSEXP, SEXP sigma_vSEXP, SEXP BSEXP, SEXP a_initSEXP, SEXP P_initSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type z(zSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma_u(sigma_uSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma_v(sigma_vSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type a_init(a_initSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type P_init(P_initSEXP);
    rcpp_result_gen = Rcpp::wrap(kalman_dk(y, z, sigma_u, sigma_v, B, a_init, P_init));
    return rcpp_result_gen;
END_RCPP
}
// loglik_normal
arma::vec loglik_normal(arma::mat u, arma::mat sigma);
RcppExport SEXP _bvartools_loglik_normal(SEXP uSEXP, SEXP sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type u(uSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma(sigmaSEXP);
    rcpp_result_gen = Rcpp::wrap(loglik_normal(u, sigma));
    return rcpp_result_gen;
END_RCPP
}
// post_coint_kls
Rcpp::List post_coint_kls(arma::mat y, arma::mat beta, arma::mat w, arma::mat sigma_i, double v_i, arma::mat p_tau_i, arma::mat g_i, Rcpp::Nullable<Rcpp::NumericMatrix> x, Rcpp::Nullable<Rcpp::NumericVector> gamma_mu_prior, Rcpp::Nullable<Rcpp::NumericMatrix> gamma_v_i_prior);
RcppExport SEXP _bvartools_post_coint_kls(SEXP ySEXP, SEXP betaSEXP, SEXP wSEXP, SEXP sigma_iSEXP, SEXP v_iSEXP, SEXP p_tau_iSEXP, SEXP g_iSEXP, SEXP xSEXP, SEXP gamma_mu_priorSEXP, SEXP gamma_v_i_priorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type w(wSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma_i(sigma_iSEXP);
    Rcpp::traits::input_parameter< double >::type v_i(v_iSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type p_tau_i(p_tau_iSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type g_i(g_iSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::NumericMatrix> >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::NumericVector> >::type gamma_mu_prior(gamma_mu_priorSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::NumericMatrix> >::type gamma_v_i_prior(gamma_v_i_priorSEXP);
    rcpp_result_gen = Rcpp::wrap(post_coint_kls(y, beta, w, sigma_i, v_i, p_tau_i, g_i, x, gamma_mu_prior, gamma_v_i_prior));
    return rcpp_result_gen;
END_RCPP
}
// post_coint_kls_sur
Rcpp::List post_coint_kls_sur(arma::mat y, arma::mat beta, arma::mat w, arma::mat sigma_i, double v_i, arma::mat p_tau_i, arma::mat g_i, Rcpp::Nullable<Rcpp::NumericMatrix> x, Rcpp::Nullable<Rcpp::NumericVector> gamma_mu_prior, Rcpp::Nullable<Rcpp::NumericMatrix> gamma_v_i_prior);
RcppExport SEXP _bvartools_post_coint_kls_sur(SEXP ySEXP, SEXP betaSEXP, SEXP wSEXP, SEXP sigma_iSEXP, SEXP v_iSEXP, SEXP p_tau_iSEXP, SEXP g_iSEXP, SEXP xSEXP, SEXP gamma_mu_priorSEXP, SEXP gamma_v_i_priorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type w(wSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma_i(sigma_iSEXP);
    Rcpp::traits::input_parameter< double >::type v_i(v_iSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type p_tau_i(p_tau_iSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type g_i(g_iSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::NumericMatrix> >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::NumericVector> >::type gamma_mu_prior(gamma_mu_priorSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::NumericMatrix> >::type gamma_v_i_prior(gamma_v_i_priorSEXP);
    rcpp_result_gen = Rcpp::wrap(post_coint_kls_sur(y, beta, w, sigma_i, v_i, p_tau_i, g_i, x, gamma_mu_prior, gamma_v_i_prior));
    return rcpp_result_gen;
END_RCPP
}
// post_normal
arma::vec post_normal(arma::mat y, arma::mat x, arma::mat sigma_i, arma::vec a_prior, arma::mat v_i_prior);
RcppExport SEXP _bvartools_post_normal(SEXP ySEXP, SEXP xSEXP, SEXP sigma_iSEXP, SEXP a_priorSEXP, SEXP v_i_priorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma_i(sigma_iSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type a_prior(a_priorSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type v_i_prior(v_i_priorSEXP);
    rcpp_result_gen = Rcpp::wrap(post_normal(y, x, sigma_i, a_prior, v_i_prior));
    return rcpp_result_gen;
END_RCPP
}
// post_normal_sur
arma::vec post_normal_sur(arma::mat y, arma::mat z, arma::mat sigma_i, arma::vec a_prior, arma::mat v_i_prior);
RcppExport SEXP _bvartools_post_normal_sur(SEXP ySEXP, SEXP zSEXP, SEXP sigma_iSEXP, SEXP a_priorSEXP, SEXP v_i_priorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type z(zSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma_i(sigma_iSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type a_prior(a_priorSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type v_i_prior(v_i_priorSEXP);
    rcpp_result_gen = Rcpp::wrap(post_normal_sur(y, z, sigma_i, a_prior, v_i_prior));
    return rcpp_result_gen;
END_RCPP
}
// ssvs
Rcpp::List ssvs(arma::vec a, arma::vec tau0, arma::vec tau1, arma::vec prob_prior, Rcpp::Nullable<Rcpp::IntegerVector> include);
RcppExport SEXP _bvartools_ssvs(SEXP aSEXP, SEXP tau0SEXP, SEXP tau1SEXP, SEXP prob_priorSEXP, SEXP includeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type a(aSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type tau0(tau0SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type tau1(tau1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type prob_prior(prob_priorSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type include(includeSEXP);
    rcpp_result_gen = Rcpp::wrap(ssvs(a, tau0, tau1, prob_prior, include));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_bvartools_bvs", (DL_FUNC) &_bvartools_bvs, 7},
    {"_bvartools_ir", (DL_FUNC) &_bvartools_ir, 5},
    {"_bvartools_kalman_dk", (DL_FUNC) &_bvartools_kalman_dk, 7},
    {"_bvartools_loglik_normal", (DL_FUNC) &_bvartools_loglik_normal, 2},
    {"_bvartools_post_coint_kls", (DL_FUNC) &_bvartools_post_coint_kls, 10},
    {"_bvartools_post_coint_kls_sur", (DL_FUNC) &_bvartools_post_coint_kls_sur, 10},
    {"_bvartools_post_normal", (DL_FUNC) &_bvartools_post_normal, 5},
    {"_bvartools_post_normal_sur", (DL_FUNC) &_bvartools_post_normal_sur, 5},
    {"_bvartools_ssvs", (DL_FUNC) &_bvartools_ssvs, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_bvartools(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
