use log::{debug, error, info, trace, warn};
use log4rs;

fn main() {
    log4rs::init_file("src/log.yaml", Default::default()).unwrap();
    trace!("detailed tracing info");
    debug!("debug info");
    info!("relevant general info");
    warn!("warning this program doesn't do much");
    error!("error message here");
}
