% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{loglik_normal}
\alias{loglik_normal}
\title{Calculates the log-likelihood of a multivariate normal distribution.}
\usage{
loglik_normal(u, sigma)
}
\arguments{
\item{u}{a \eqn{K \times T} matrix of residuals.}

\item{sigma}{a \eqn{K \times K} or \eqn{KT \times K} variance-covariance matrix.}
}
\description{
Calculates the log-likelihood of a multivariate normal distribution.
}
\details{
The log-likelihood is calculated for each vector in period \eqn{t} as
\deqn{-\frac{K}{2} \ln 2\pi - \frac{1}{2} \ln |\Sigma_t| -\frac{1}{2} u_t^\prime \Sigma_t^{-1} u_t},
where \eqn{u_t = y_t - \mu_t}.
}
\examples{

# Load data
data("e1")
e1 <- diff(log(e1))

# Generate VAR model
data <- gen_var(e1, p = 2, deterministic = "const")
y <- t(data$data$Y)
x <- t(data$data$Z)

# LS estimate
ols <- tcrossprod(y, x) \%*\% solve(tcrossprod(x))

# Residuals
u <- y - ols \%*\% x # Residuals

# Covariance matrix
sigma <- tcrossprod(u) / ncol(u)

# Log-likelihood
loglik_normal(u = u, sigma = sigma)

}
